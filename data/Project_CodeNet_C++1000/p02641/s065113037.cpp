#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef map<string, int> msi;
typedef pair<int, int> PII;

int main() {
    int x, n; cin >> x >> n;
    vector<int> v(n);
    rep(i, n){
        cin >> v.at(i);
    }
    int sub = 1000000;
    int ans;
    rep(i, 102){
        bool flag = false;
        for(auto j : v){
            if(i == j) {
                flag = true;
                break;
            }
        }
        if(flag) continue;
        if(sub > abs(x-i)){
            sub = abs(x-i);
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}