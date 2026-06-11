#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main(){
    ll N;cin>>N;
    vector<pair<ll,ll>> t(N);
    for (ll i = 0; i < N; i++){
        ll a,b; cin>>a>>b;
        t[i]=make_pair(b,a);
    }
    sort(t.begin(),t.end());
    ll time=0;
    for (ll i = 0; i < N; i++){
        ll x=t[i].second;
        time+=x;
        //cout<<time<<" "<<t[i].first<<endl;
        if(time>t[i].first){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}
