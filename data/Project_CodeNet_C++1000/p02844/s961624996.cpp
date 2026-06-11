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
    for(int i = 0;i < 1000;i++){
        vec A = {i/100, i/10-(i/100)*10, i-(i/10)*10};
        int f = 0;
        for(int j = 0;j < n;j++){
            char c = s[j];
            if(int(c)-48 == A[f]){
                f++;
            }
            if(f == 3){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}