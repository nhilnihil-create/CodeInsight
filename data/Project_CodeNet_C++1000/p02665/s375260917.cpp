#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n;
    cin>>n;
    vector<ll> v(n+1);
    rep(i, n+1){
        cin>>v[i];
    }
    vector<pair<ll, ll> > minmax(n+1);
    minmax[n] = make_pair(v[n], v[n]);
    for(int i = n-1;i>=0;i--){
        minmax[i] = make_pair((minmax[i+1].first+2-1)/2+v[i], minmax[i+1].second+v[i]);
    }
    if(!(minmax[0].first<=1 && minmax[0].second>=1)){
        cout<<-1<<endl;
        return 0;
    }
    ll now = 1;
    ll ans = 1;
    for(int i = 1;i<=n;i++){
        now = min((now-v[i-1])*2, minmax[i].second);
        ans += now;
    }
    cout<<ans<<endl;
    return 0;
}