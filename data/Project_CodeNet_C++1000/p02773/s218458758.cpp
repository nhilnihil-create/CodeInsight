#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef map<string, int> msi;

int main(){
    int n; cin >> n;
    msi m;
    rep(i, n){
        string s; cin >> s;
        m[s] += 1;
    }
    int max = 0;
    for(const auto&x : m) {
        int v = x.second;
        if(v > max) max = v;
    }
    for(const auto&x : m){
        if(x.second == max) cout << x.first << endl;
    }
    return 0;
}
