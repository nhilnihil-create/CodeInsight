#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    int n,h;cin >>h>>n;
    vector<pair<int,int>>magic(n);
    for (int i = 0; i < n; ++i) {
        int a,b;cin >>a>>b;
        magic[i]={a,b};
    }
    vector<int>dp(h+1,INF);
    dp[0]=0;
    for (int i = 0; i < n; ++i) {
        int damage,cost;
        damage=magic[i].first;
        cost=magic[i].second;
        for (int j = 0; j <=h; ++j) {
            int k = min(j + damage, h);
            dp[k]=min(dp[k],dp[j]+cost);
        }
    }
    cout <<dp[h]<<endl;
    return 0;
}