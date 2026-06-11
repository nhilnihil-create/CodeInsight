#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() { 
    int K;
    string target = "ACL", ans;
    cin >> K;
    rep(i, K) {
        ans += target;
    }
    cout << ans <<"\n";
    return 0;
}
