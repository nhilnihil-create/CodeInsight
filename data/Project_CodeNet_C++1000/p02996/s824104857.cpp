#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 200005

int N;
struct Info{
	bool operator<(const struct Info &arg) const{

		return B < arg.B;
	}
	ll A,B;
};
Info info[SIZE];


int main(){

	scanf("%d",&N);
	for(int i = 0; i < N; i++){

		scanf("%lld %lld",&info[i].A,&info[i].B);
	}
	sort(info,info+N);

	ll current = 0;
	for(int i = 0; i < N; i++){
		current += info[i].A;
		if(current > info[i].B){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");

	return 0;
}
