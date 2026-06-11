/**
 *    author:  FromDihPout
 *    created: 2020-08-19
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();
    vector<int> left(n), right(n);
    for (int i = n - 1; i >= 0; i--) {
        left[i] = (s[i] == 'L' ? i : left[i+1]);
    }
    for (int i = 0; i < n; i++) {
        right[i] = (s[i] == 'R' ? i : right[i-1]);
    }
    
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            if ((right[i] - i) % 2 == 0) {
                ans[right[i]]++;
            }
            else {
                ans[right[i] + 1]++;
            }
        }
        else {
            if ((left[i] - i) % 2 == 0) {
                ans[left[i]]++;
            }
            else {
                ans[left[i] - 1]++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) { 
        cout << ans[i] << ' ';
    }
    cout << '\n';
}