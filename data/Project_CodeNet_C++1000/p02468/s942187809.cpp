#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
#define int long long
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF (long long)(1e18)
#define MOD (int)(1e9+7)
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
#define yn(f) (f?"Yes":"No")
#define YN(f) (f?"YES":"NO")
#define pro "はいプロ　世界一○○が上手　○○界のtourist　○○時代の終焉を告げる者　実質○○　○○するために生まれてきた男"
#define Answer_to_the_Ultimate_Question_of_Life_the_Universe_and_Everything 42

long long power(long long x, long long n){
	long long ans = 1;
	for(;n;n>>=1,x*=x,ans%=MOD,x%=MOD)
		if(n&1)ans*=x;
	return ans%MOD;
}

signed main(){
	cout<<fixed<<setprecision(7);
	
	int m, n;
	
	cin>>m>>n;
	
	cout<<power(m,n)<<endl;
	
	
	return 0;
}
