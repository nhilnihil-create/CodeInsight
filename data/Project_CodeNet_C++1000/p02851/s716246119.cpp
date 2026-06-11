#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 200005

ll N,K;
ll A[SIZE],S[SIZE];
map<ll,ll> MAP;

int main(){

	scanf("%lld %lld",&N,&K);

	S[0] = 0;

	for(int i = 0; i < N; i++){

		scanf("%lld",&A[i]);
		A[i]--;
		S[i+1] += S[i]+A[i];
		S[i+1] %= K;
	}

	ll ans = 0;
	queue<ll> Q;

	for(int i = 0; i <= N; i++){

		ans += MAP[S[i]];
		MAP[S[i]]++;
		Q.push(S[i]);

		if(Q.size() == K){

			MAP[Q.front()]--;
			Q.pop();
		}
	}

	printf("%lld\n",ans);

	return 0;
}
