#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;


int main() {

    int n,k; cin >> n >> k;
    int r,s,p; cin >> r >> s >> p;
    ll ans = 0;
    string t; cin >> t;
    vector<ll>h(100001,-1);
    int ppos = 100000,spos = 100000,rpos = 100000;

    rep(i,t.length()){
        if(i < k){
            if(t[i] == 'p'){
                ans += s;
                h[i] = 0;
            }else if(t[i] == 's'){
                ans += r;
                h[i] = 1;
            }else if(t[i] == 'r'){
                ans += p;
                h[i] = 2;
            }
        }else{
            if(t[i] == 'p' && h[i-k] != 0){
                h[i] = 0;
                ans += s;
            }else if(t[i] == 's' && h[i-k] != 1){
                h[i] = 1;
                ans += r;
            }else if(t[i] == 'r' && h[i-k] != 2){
                h[i] = 2;
                ans += p;
            }
        }
    }
    cout << ans;
    return 0;
}
