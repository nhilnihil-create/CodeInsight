#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1e9+7


int main(){
    int n,m;
    cin >> n >> m;
    map<int,ll,greater<ll>> mp;
    rep(i,n){
        int a;
        cin >> a;
        mp[a]++;
    }
    rep(i,m){
        int temp;
        for(auto x:mp){
            if(x.second<=0) continue;
            mp[x.first/2]++;
            mp[x.first]--;
            temp=x.first;
            break;
        }
        if(mp[temp]<=0) mp.erase(temp);
    }
    ll ans=0;
    for(auto x:mp){
        //cout << x.first << " " << x.second << endl;
        if(x.second<=0) continue;
        ans+=x.first*x.second;
    }
    cout << ans << endl;
}