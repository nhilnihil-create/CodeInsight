/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.20 21:11:44
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    int n;cin >> n;
    ll k;cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<int>> doubling(64,vector<int>(n));
    for (int i = 0; i < n; i++) {
        doubling[0][i] = a[i];
    }
    for (int i = 1; i < 64; i++) {
        for (int j = 0; j < n; j++) {
            doubling[i][j] = doubling[i-1][doubling[i-1][j]];
        }
    }
    int now = 0;
    int t = 0;
    while(k >= (1LL << t)) {
        if (k & (1LL << t)) {
            now = doubling[t][now];
        }
        t++;
    }
    cout << now + 1 << endl;
    return 0;
}