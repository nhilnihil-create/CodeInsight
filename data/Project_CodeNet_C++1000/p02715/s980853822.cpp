#include <bits/stdc++.h>
using namespace std;
// typedef long long LL;
// typedef unsigned long long UL;
// typedef pair<int, int> P;
// typedef pair<int, P> PPI;
// typedef pair<LL, LL> PL;
// typedef long long LL;
// // LLONG_MIN, INT_MIN
// #define xx first
// #define yy second
// const LL INF = 1000000000;
#define RG register int
#define LL long long
struct edge
{
    LL to, cost;
    edge(int a, int b):to(a), cost(b){}
};

void debug(vector<int>& db){
  for(auto x:db)
    cout<<x<<" ";
  cout<<endl;
}

LL mod = 1000000007;
LL my_pow(LL a, LL b){
  LL re = 1;
  while(b){
    if(b&1)re = (re*a)%mod;
    a = (a*a)%mod;
    b >>= 1;
  }
  return re;
}


int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    LL n,k;
    cin>>n>>k;
    LL ans = my_pow(k, n);
    vector<LL> cnt(k+1);
    for(LL i=k;i>=2;i--){
      cnt[i] = my_pow(k/i, n);
      for(LL j = i*2;j<=k;j+=i)
        cnt[i] = (cnt[i] - cnt[j]+mod)%mod;
      ans += cnt[i]*(i-1);
      ans %= mod;
    }
    cout<<ans<<endl;
}
