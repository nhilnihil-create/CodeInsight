#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    ll n;
    ll k;
    cin >> n>>k;
    vector<ll> loop(n);
    map<ll,pair<ll,ll>> data;
    rep(i,0,n){
        cin >> loop[i];
    }
    rep(i,0,n){
        rep(j,0,n){
            if(loop[i]<loop[j]&&i>j){
                data[i].first++;
                data[i].second++;

            }else if(loop[i]<loop[j]&&i<j){
                data[i].second++;
            }
        }
    }
    //cout<<data[1].first<<data[1].second<<endl;
    ll ans=0;
    rep(i,0,n){
        ans+=(data[i].first*k)%MOD;
        ans%=MOD;
        ans+=((k-1)*k/2%MOD)*data[i].second%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;


  return 0;
}