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
    ll now1 = 0;
    ll now2 = 0;
    for(ll i=0;i<N;i++)
    {
        now1+=tasks[i].second;
        if(tasks[i].first<now1){
            ok=false;break;
        }
        now2+=tasks[i].second;
        if(tasks[i].first<now2){
            ok=false;break;
        }
        now1=min(now1,now2);
        now2=max(now1,now2);
    }
    if(ok) cout<<"Yes";
    else cout<<"No";
}