#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vec = vector<ll>;
using vec2 = vector<vector<ll>>;
ll inf = pow(2,62);

int main(){
    ll n;cin >> n;
    string s;cin >> s;
    ll ans = 0;
    ll p = s.size();
    for(int i = 0;i < n-2;i++){
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C'){
            ans++;
        }
    }
    cout << ans << endl;
}