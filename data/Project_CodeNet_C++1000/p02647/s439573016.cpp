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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for(auto& val: arr) {
        cin >> val;
    }
    while(k--) {
        vector<int> var(n+1, 0);
        for(int i = 0; i < n; i++) {
            var[max(i - arr[i], 0)] += 1;
            var[min(n, i + arr[i]+1)] -= 1;
        }
        vector<int> new_arr(n);
        int cur = 0;
        ll acc = 0;
        for(int i = 0; i < n; i++) {
            cur += var[i];
            new_arr[i] = cur;
            // cout << cur << " ";
            acc += cur;
        }
        arr = new_arr;
        if (acc == ll(n)*ll(n))
            break;
    }
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
