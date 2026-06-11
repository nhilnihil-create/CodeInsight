#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using v  = vector<ll>;


int main(){
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    
    vector<pair<ll,int>> p(a+b+c);
    rep(i,a+b+c){
        cin>>p[i].first;
        if(i<a)
            p[i].second = 0;
        else if(i<a+b)
            p[i].second = 1;
        else
            p[i].second = 2;
    }
    
    sort(p.rbegin(), p.rend());
    
    ll ans = 0;
    
    vector<int> count(3,0), lim(3);
    lim[0] = x;
    lim[1] = y;
    lim[2] = x+y;
    
    rep(i,a+b+c){
        int t = p[i].second;
        if(count[t]>=lim[t] || count[2]>=lim[2])continue;
        ans += p[i].first;
        if(t!=2)count[t]++;
        count[2]++;
    }
    
    cout << ans << endl;
    
    return 0;
}