#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll X,Y,A,B,C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> red(A);
    vector<ll> green(B);
    vector<ll> nocolor(C);
    rep(i,A){
        cin >> red[i];
    }
    rep(i,B){
        cin >> green[i];
    }
    rep(i,C){
        cin >> nocolor[i];
    }
    sort(all(red));
    sort(all(green));
    sort(all(nocolor));
    vector<ll> allapple(0);
    for (ll i = 1; i <= X; i++){
        allapple.push_back(red[A - i]);
    }
    for (ll i = 1; i <= Y; i++){
        allapple.push_back(green[B - i]);
    }
    rep(i,C){
        allapple.push_back(nocolor[i]);
    }
    sort(all(allapple));
    ll ans = 0;
    ll len = allapple.size();
    for (ll i = 1; i <= X + Y; i++){
        ans += allapple[len - i];
    }
    cout << ans << endl;
}
