/*
      author : Nishikawa
      created: 10.08.2020 13:21:07
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    vector<bool> top(n,true);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        --a; --b;
        if(h[a] >= h[b]) top[b]=false;
        if(h[a] <= h[b]) top[a]=false;
    }
    int ans = 0;
    rep(i,n) if(top[i]) ans++;
    cout << ans << endl;
    return 0;
}