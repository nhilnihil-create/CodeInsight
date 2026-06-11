#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    long long k;
    cin >> n >> m >> k;
    long long asum = 0;
    vector<long long> a;
    vector<long long> b;
    long long book;
    for (int i = 0; i < n; i++) { 
        cin >> book;
        asum += book;
        a.push_back(asum);
    }
    long long bsum = 0;
    for (int i = 0; i < m; i++) {
        cin >> book;
        bsum += book;
        b.push_back(bsum);
    }
    int j = m - 1;
    while (j >= 0 && b[j] > k) {
        j--;
    }
    int sol = j + 1; 
    for (int i = 0; i < n; i++) {
        while (j >= 0 && a[i] + b[j] > k) {
            j--;
        }
        if (i + j + 2 > sol && a[i] <= k){
            sol = i + j + 2;
        }
    }
    cout << sol;
}
