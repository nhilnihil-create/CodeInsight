#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 200005

struct Info{
	bool operator<(const struct Info &arg) const{

		return X < arg.X;
	}
	ll X,H;
};

ll uniformity[4*NUM],partial[4*NUM];
ll N = 1;
ll D,A;
Info info[NUM];


void init(ll first_N){
	while(N < first_N)N *= 2;
}

void add(ll left,ll right,ll value,ll node_id,ll node_left,ll node_right){

	if(right <= node_left || left >= node_right)return;
	else if(left <= node_left && right >= node_right){
		uniformity[node_id] += value;
	}else{
		partial[node_id] += (min(right,node_right)-max(left,node_left))*value;
		add(left,right,value,2*node_id+1,node_left,(node_left+node_right)/2);
		add(left,right,value,2*node_id+2,(node_left+node_right)/2,node_right);
	}
}

ll getSum(ll left,ll right,ll node_id,ll node_left,ll node_right){
	if(right <= node_left || left >= node_right)return 0;
	else if(left <= node_left && right >= node_right){
		return (node_right-node_left)*uniformity[node_id]+partial[node_id];

	}else{
		ll sum = (min(right,node_right)-max(left,node_left))*uniformity[node_id];

		sum += getSum(left,right,2*node_id+1,node_left,(node_left+node_right)/2);
		sum += getSum(left,right,2*node_id+2,(node_left+node_right)/2,node_right);
		return sum;
	}
}


int main(){

	ll first_N;
	scanf("%lld %lld %lld",&first_N,&D,&A);

	init(first_N);

	for(ll i = 0; i <= 2*N-2; i++){
		uniformity[i] = 0;
		partial[i] = 0;
	}

	for(int i = 0; i < first_N; i++){

		scanf("%lld %lld",&info[i].X,&info[i].H);
	}
	sort(info,info+first_N);

	for(int i = 0; i < first_N; i++){

		add(i,i+1,info[i].H,0,0,N); //半開区間
	}

	int L = 0;
	ll ans = 0,ADD;

	int left,right,mid;
	int R;

	while(true){

		ll left_HP = getSum(L,L+1,0,0,N);

		//printf("L:%d left_HP:%lld\n",L,left_HP);

		if(left_HP%A == 0){

			ADD = left_HP/A;
		}else{

			ADD = left_HP/A+1;
		}

		ans += ADD;

		left = L,right = first_N-1,mid = (left+right)/2;
		R = L;

		while(left <= right){
			if(info[mid].X <= info[L].X+2*D){

				R = mid;
				left = mid+1;
			}else{

				right = mid-1;
			}
			mid = (left+right)/2;
		}

		add(L,R+1,-A*ADD,0,0,N);

		L++;
		while(L < first_N){
			if(getSum(L,L+1,0,0,N) > 0){

				break;
			}
			L++;
		}
		if(L == first_N)break;
	}

	printf("%lld\n",ans);

	return 0;
}
