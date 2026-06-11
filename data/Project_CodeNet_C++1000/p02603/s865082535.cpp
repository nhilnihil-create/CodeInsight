#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> v(100);
    int cur = 0, turn = 0;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] < a[i+1]) {
            turn = 1;
            v[cur].push_back(i);
        } else {
            if(turn == 1) {
                turn = 0;
                cur++;
            }
        }
    }
    long long start = 1000;
    for(int i = 0; i < 100; i++) {
        if(v[i].size() > 0) {
            int sz = v[i].size();
            int rest = start % a[v[i][0]];
            start /= a[v[i][0]];
            start *= a[v[i][sz-1]+1];
            start += rest;
        }
    }
    cout << start << "\n";
    return 0;
}