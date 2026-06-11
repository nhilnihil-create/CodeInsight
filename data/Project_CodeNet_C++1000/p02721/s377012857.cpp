#include <bits/stdc++.h>
//#include "atcoder/all"
typedef long long int ll;
using namespace std;
// using namespace atcoder;
int main() {
    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;
    int used[n];
    memset(used, -1, sizeof(used));
    int index = 0;
    int count = 0;
    while ((index < n)&&(count < k)) {
        if (s[index] == 'o') {
            // cout << index << endl;
            // cout << count << endl;
            used[index] = count;
            index += c + 1;
            count++;
        }
        else {
            index++;
        }
    }
    index = n - 1;
    count = 0;
    vector<int> ans;
    while ((index >= 0)&&(count < k)) {
        if (s[index] == 'o') {
            // cout << index << endl;
            if (used[index] == k - count - 1) {
                ans.push_back(index);
            }
            index -= c + 1;
            count++;
        }
        else {
            index--;
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << endl;
    }
    return 0;
}