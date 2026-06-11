#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

long long int powmod(long long int x, long long int n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>=1;
    }
    
    return res;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> D(n);
    for (int i = 0; i < n; ++i) {
        cin >> D[i];
    }
    if (D[0] != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    map<int, int> M;
    for (int i = 0; i < n; ++i) {
        ++M[D[i]];
    }
    if (M[0] != 1) {
      cout << 0 << endl;
      return 0;
    }
  
    int pred = -1;
    vector<int> dcnt;
    for (auto itr = M.begin(); itr != M.end(); ++itr) {
        int curd = itr->first;
        if (curd != pred + 1) {
            cout << 0 << endl;
            return 0;
        }
        dcnt.push_back(itr->second);
        pred = curd;
    }
    
    long long res = 1;
    for (int i = 0; i < (int)dcnt.size() - 1; ++i) {
        res *= powmod(dcnt[i], dcnt[i + 1]);
        res %= MOD;
    }
    cout << res << endl;
    
    return 0;
}