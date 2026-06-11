#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define chmax(a,b) a = max(a,b)
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using vi = vector<int>;

int main(){
    int h, w, m;
    cin >> h >> w >> m;
    vi bomh(h, 0), bomw(w, 0);
    set<P> bombs;
    rep(i,m){
        int a,b; cin>>a>>b; a--;b--;
        bomh[a]++;
        bomw[b]++;
        bombs.insert(P(a,b));
    }
    set<int> argh, argw;
    int maxh = 0, maxw = 0;
    rep(i,h)chmax(maxh, bomh[i]);
    rep(i,w)chmax(maxw, bomw[i]);
    rep(i,h)if(maxh==bomh[i])argh.insert(i);
    rep(i,w)if(maxw==bomw[i])argw.insert(i);
    
    ll count = (ll)argh.size()*argw.size();
    int ans = maxh+maxw;
    if(count>bombs.size()){
        cout<< ans <<endl;
        return 0;
    }
    
    for(auto b: bombs){
        int h = b.first;
        int w = b.second;
        if(argh.count(h) && argw.count(w))
            count--;
    }
    
    if(!count)
        cout << ans-1 << endl;
    else
        cout << ans << endl;
    return 0;
}