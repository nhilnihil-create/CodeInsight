#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    double n; cin >> n;
    double count = 0;
    rep(i, n){
        if((i+1) % 2 == 1) count++;
    }
    double ans = count / n;
    cout << ans << endl;
    return 0;
}
