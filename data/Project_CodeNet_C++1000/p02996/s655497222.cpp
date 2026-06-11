#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll N;
    cin>>N;
    vector<pair<ll,ll>> tasks;
    bool ok = true;
    for(int i=0;i<N;i++){
        ll a,b;cin>>a>>b;
        tasks.push_back(make_pair(b,a));
    }
    sort(tasks.begin(),tasks.end());
    //for(int i=0;i<N;i++)cout<<tasks[i].first<<endl;
    ll now = 0;
    for(ll i=0;i<N;i++)
    {
        now+=tasks[i].second;
        if(tasks[i].first<now){
            ok=false;break;
        }
    }
    if(ok) cout<<"Yes";
    else cout<<"No";
}