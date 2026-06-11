#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 100000000
const int MOD = 1000000007;

long long modpow(long long a,long long n,long long p)
{
    if(n==1)
    {
        return a%p;
    }
    if(n%2==1)
    {
         return a*modpow(a,n-1,p)%p;
    }
    long long t = modpow(a,n/2,p);
    return t*t%p;
}
int comb( int N, int K ){
    int X = 1; //分子
    int Y = 1; //分母
    for( int i = N; i > N-K; i-- ){
        X = (X*i)%MOD;
    }
    for( int i = 1; i <= K; i++ ){
        Y = (Y*i)%MOD;
    }
    return X * modpow(Y, MOD-2, MOD)%MOD;
}
int main()
{
    int n;
    cin>>n;
    vector <string> s(n);
    unordered_map <string,ll> mp;   //ハッシュテーブル
    for(int i=0;i<n;i++) 
    {
        cin>>s[i];
        sort(s[i].begin(),s[i].end());
        mp[s[i]]++;
    }

    ll ans = 0;
    for(auto p:mp)
    {
        ans += p.second*(p.second-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}