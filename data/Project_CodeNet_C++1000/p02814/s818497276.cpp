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
vector<int> to[20009];
vector<int> ans;
void dfs(int i,int j=-1){
    for(int v:to[i]){
        if(v==j)continue;
        ans[v]+=ans[i];
        dfs(v,i);
    }
}
int main(void){ 
    ll n,m;cin>>n>>m;
    ll a[n],b[n];
    rep(i,n){
        cin>>a[i];a[i]/=2;
        b[i]=a[i];
    }
    int k=0;
    while(b[0]%2==0){
        k++;
        b[0]/=2;
        //cout<<0<<" "<<k<<b[0]<<endl;
    }
    bool t=false;
    for(int i=1;i<n;i++){
        int w=0;
        while(b[i]%2==0){
        w++;
        b[i]/=2;
    }
    //cout<<i<<" "<<w<<endl;
    if(w!=k)t=true;
    }
    if(t){
        cout<<0<<endl;
        return 0;
    }
    ll lc=1;
    for(int i=0;i<n;i++){
        lc=lcm(lc,a[i]);
    }
    cout<<(m/lc+1)/2<<endl;
    
}

