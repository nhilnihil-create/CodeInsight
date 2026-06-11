#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vec = vector<ll>;
using vec2 = vector<vector<ll>>;
ll inf = pow(2, 62);

int main(){
    string s, t;
    cin >> s >> t;
    ll ans = 0;
    rep(i,s.size()){
        if(s[i] != t[i]){
            ans++;
        }
    }
    cout << ans << endl;
}
