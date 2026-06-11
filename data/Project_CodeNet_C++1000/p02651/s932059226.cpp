#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

ll apply(vector <ll> &g, ll x){
    while(x > 0 && g[__lg(x)] > 0){
        x ^= g[__lg(x)];
    }
    return x;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector <ll> a(n);
        for(auto &i : a) cin >> i;
        string s;
        cin >> s;
        vector <ll> g(60);
        char ans = '0';
        for(int i = n - 1 ; i >= 0 ; i--){
            if(s[i] == '0'){
                ll x = apply(g, a[i]);
                if(x > 0) g[__lg(x)] = x;
            }
            else{
                if(apply(g, a[i]) > 0){
                    ans = '1';
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}
