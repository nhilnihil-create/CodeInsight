#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<55)
#define mod 1000000007
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
    ll n,m;cin>>n>>m;
    vector<P> p(n);
    priority_queue<ll> que;
    rep(i,n){
        ll a,b;cin>>a>>b;
        p[i]={a,b};
    }
    sort(p.begin(),p.end());

    ll ans=0,num=0;
    rep(i,m+1){//後ろからi日目の時を考える
        que.push(0);
        while(num<n){
            if(p[num].first<=i){
                que.push(p[num++].second);
            }else{
                break;
            }
        }

        ll mx=que.top();
        ans+=mx;
        que.pop();
    }

    cout<<ans<<endl;

    return 0;
}