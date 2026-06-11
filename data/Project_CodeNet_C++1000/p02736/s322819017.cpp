#include "bits/stdc++.h"

#define pb push_back

using namespace std;

const int MOD = 2;

int n, x = 0;
string s;
vector<int> v, f;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    f.assign(1e6 + 5, 0);
    for(int i = 1; i < 1e6 + 5; ++i){
        f[i] = i/2 + f[i/2];
        // cout << f[i] << " ";
    }
    for(int i = 0; i < n; ++i){
        v.pb(s[i] - 1 - '0');
    }
    for(int i = 0; i < n; ++i){
        if(v[i] == 1){
            x ^= ((f[n - 1] - f[n - 1 - i] - f[i]) == 0);
        }
    }
    if(x){
        cout << 1;
        return 0;
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(v[i] == 1) cnt++;
    }
    if(cnt){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; ++i){
        v[i] /= 2;
    }
    x = 0;
    for(int i = 0; i < n; ++i){
        if(v[i] == 1){
            x ^= ((f[n - 1] - f[n - 1 - i] - f[i]) == 0);
        }
    }
    cout << (x ? 2 : 0);
    return 0;
}