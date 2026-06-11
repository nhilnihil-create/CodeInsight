#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=(n);i<(int)(N);i++)
#define ck(n,a,b) (a)<=(n)&&(n)<=(b)
#define p(s) cout<<(s)<<endl
#define F first
#define S second
typedef long long ll;
using namespace std;

bool prime[250001];
int main() {
	int n;
	REP(i, 0, 250001) prime[i]=true;
	prime[0]=prime[1]=false;
	for(int i=2; i*i<250001; i++){
		for(int j=i*2; j<250001; j+=i){
			prime[j]=false;
		}
	}

	while(cin>>n, n){
		int cnt=0;
		REP(i, n+1, 2*n+1){
			if(prime[i]) cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}