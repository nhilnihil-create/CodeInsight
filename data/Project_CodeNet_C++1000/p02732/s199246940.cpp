#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)

const int M = 200005;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    
    vector<long int> cnt(M);
    rep(i,n) {
        cnt[a[i]]++;
    }
    
    vector<long int> con(M);
    long int sum = 0;
    rep(i,M) {
        con[i] = cnt[i] * (cnt[i] - 1) / 2;
        sum += con[i];
    }
    
    rep(i,n) {
        cout<< sum - (cnt[a[i]] - 1) << endl;
    }
    
    return 0;
}


