#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    int L, R, val;
    cin >> L >> R;
    if (R - L > 2020) {
        cout << 0 << endl;
    } else {
        int ans = INT_MAX;
        vector<int> arr;
        for(int i = L; i <= R; i++) {
            arr.push_back(i%2019);
        }

        for(int i = 0; i < arr.size(); i++)
            for(int j = i+1; j < arr.size(); j++)
                ans = min(ans, (arr[i]*arr[j])% 2019);
        cout << ans << endl;

    }
    return 0;
}

