#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    vector<int> ans(n , 0) , left(n , 0) , right(n , n);

    for (int i = 1 ;i < n ;i++) {
        if (s[i] == 'L') {
            if (s[i - 1] == 'L')
                left[i] = left[i - 1];
            else
                left[i] = i;
        }
    }

    for (int i = n - 2 ;i >= 0 ;i--) {
        if (s[i] == 'R') {
            if (s[i + 1] == 'R')
                right[i] = right[i + 1];
            else
                right[i] = i;
        }
    }


    for (int i = 0 ;i < n ;i++) {
        if (s[i] == 'R') {
            if (right[i] == n - 1) {
                ans[right[i]]++;
                continue;
            }
            int c = right[i] - i;
            if (c&1)
                ans[right[i] + 1]++;
            else
                ans[right[i]]++;
        } else {
            if (left[i] == 0) {
                ans[left[i]]++;
                continue;
            }
            int c = i - left[i];
            if (c&1)
                ans[left[i] - 1]++;
            else
                ans[left[i]]++;
        }
    }

    for (int c : ans)
        cout << c << ' ';
}
