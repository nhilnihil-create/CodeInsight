#include<bits/stdc++.h>
typedef long long   ll;
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> h(n);
    vector<int> a(m);
    vector<int> b(m);
    vector<bool> good(n, true);

    rep(i, n){
        cin >> h.at(i);
    }
    rep(i, m){
        cin >> a.at(i) >> b.at(i);
        a.at(i)--;
        b.at(i)--;
        if(h.at(a.at(i))>=h.at(b.at(i))){
            good[b[i]]=false;
        }
        if(h.at(a.at(i))<=h.at(b.at(i))){
            good[a[i]]=false;
        }
    }
    // rep(i, m){
    //     cout << min_high.at(i) << endl;
    // }
    int ans = 0;
    rep(i, n){
        if(good[i]){
            ans++;
        }
    }
    cout << ans << endl;

}