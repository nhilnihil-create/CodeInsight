#include <bits/stdc++.h>

#define tc(t) int t; cin>>t; while(t--)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    bool ok = false;
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 10; ++j) {
            if(i * j == n){
                ok = true;
                break;
            }
        }

    }
       if(ok == true) cout << "Yes" <<endl;
       else cout << "No" << endl;
}




