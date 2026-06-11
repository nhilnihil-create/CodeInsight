#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n;
    cin>>n;
    vector<pair<ll,ll>> vec(n);
    rep(i,n){
        ll x,y;
        cin>>x>>y;
        vec[i]=make_pair(x,y);
    }
    sort(vec.begin(),vec.end());
    map<pair<ll,ll>,int> mp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            mp[make_pair(vec[j].first-vec[i].first,vec[j].second-vec[i].second)]+=1;
        }
    }

    int cnt=0;
    for(auto x:mp){
        cnt = max(cnt,x.second);
    }

    cout<<n-cnt<<endl;

    return 0;
}