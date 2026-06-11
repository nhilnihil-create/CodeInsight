#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i) = 0; (i) <(n); (i)++) 
#define so(v) sort(v.begin(),v.end())
using ll = long long;
using vi=vector<int>;
using vii=vector<vi>;
const int MAX = 510000;
const int MOD = 1000000007;
ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}
ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
long long com(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


/*
* 素因数分解
* @param [in] n   自然数
* @param [in] out 素因数分解した数が入る
*/
template<typename T>
void PrimeFactors(T n, std::map<T,T> &out)
{
	while (n % 2 == 0)
	{
		++out[2];
		n = n / 2;
	}

	for (T i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n%i == 0)
		{
			++out[i];
			n = n / i;
		}
	}

	if (n > 2)
		++out[n];
}



int main(void){ 
    ll n;ll K;cin>>n>>K;
    char k[n+1];
    k[0]='0';
    k[n+1]='0';
    rep(i,n){
        cin>>k[i+1];
    }
    ll count=0;
    for(int i=0;i<=n;i++){
        if(k[i]==k[i+1]&&k[i]=='R'){count++;}
    }
    for(int i=1;i<=n+1;i++){
        if(k[i]==k[i-1]&&k[i]=='L'){count++;}
    }
    cout<<min(n-1,count+2*K)<<endl;
    
}

