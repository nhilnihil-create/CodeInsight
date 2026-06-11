#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

struct Info{
	bool operator<(const struct Info &arg) const{

		return A < arg.A;
	}
	ll A,B;
};

ll N,M;
Info info[SIZE];


int main(){

	scanf("%lld %lld",&N,&M);

	for(int i = 0; i < N; i++){

		scanf("%lld %lld",&info[i].A,&info[i].B);
	}
	sort(info,info+N);


	if(info[0].A > M){

		printf("0\n");
		return 0;
	}

	priority_queue<ll> Q;
	int index = 0;
	ll ans = 0;

	for(int day = 1; day <= M; day++){

		while(index < N && info[index].A == day){

			Q.push(info[index].B);
			index++;
		}

		if(!Q.empty()){
			ans += Q.top();
			Q.pop();
		}
	}

	printf("%lld\n",ans);

	return 0;
}
