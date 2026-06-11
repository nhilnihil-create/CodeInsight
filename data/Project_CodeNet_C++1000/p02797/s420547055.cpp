#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, k, s;
    cin >> n >> k >> s;
    vector<int> ans;
    if(s == 1) {
        for(int i = 0; i < k; i++) {
            ans.push_back(1);
        }
        for(int i = 0; i < n - k; i++) {
            ans.push_back(3);
        }
    }
    else if(s == 2) {
        for(int i = 0; i < k; i++) {
            ans.push_back(2);
        }
        for(int i = 0; i < n - k; i++) {
            ans.push_back(3);
        }
    }
    else {
        for(int i = 0; i < k; i++) {
            ans.push_back(s);
        }
        for(int i = 0; i < n - k; i++) {
            ans.push_back(s-1);
        }
    }
    for(int i = 0; i < n - 1; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[n-1] << "\n";
    return 0;
}