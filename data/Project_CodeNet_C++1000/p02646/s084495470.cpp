#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    ll a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;
    if (w > v) {
        cout << "NO" << endl;
    } else {
        if (llabs(v-w)*t >= llabs(a-b))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
