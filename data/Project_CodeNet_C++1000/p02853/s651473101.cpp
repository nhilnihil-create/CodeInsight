#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    vector<int> rank(2, 0);
    cin >> rank[0] >> rank[1];
    if (rank[0] == 1 && rank[1] == 1) {
        cout << 1000000 << endl;
    } else {
        int ans = 0;
        for(int i = 0; i < 2; i++) {
            if (rank[i] == 1)
                ans += 300000;
            else if (rank[i] == 2)
                ans += 200000;
            else if (rank[i] == 3)
                ans += 100000;
        }
        cout << ans << endl;
    }
    return 0;
}

