//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;
int main(){
    ll n; cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    vector<ll>cnt(1e6+10,0);

    for(auto x:a){
               if(cnt[x]!=0){
            cnt[x]=2;
            continue;
               }
        
            for(ll i=x;i<1e6+10;i+=x){
                cnt[i]++;

        }
    }
    ll ans=0;
    for(auto x:a){
        if(cnt[x]==1){
            //cout<<x<<" ";
            ans++;
    }
    }
    //cout<<endl;
    cout<<ans<<endl;
}












































































