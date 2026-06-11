#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main()
{
    int n;cin>>n;
    vector<pair<ll,ll>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    map<pair<ll,ll>,ll> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            auto m=make_pair(v[i].first-v[j].first,v[i].second-v[j].second);
            mp[m]++;
        }
    }
    ll ans=0;
    for(auto e:mp){
        //cout<<e.first.first<<":"<<e.first.second<<endl;
        ans=max(ans,e.second);
    }
    cout<<n-ans<<endl;
}