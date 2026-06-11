#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;

int main() {
    int n, k, q; cin >> n >> k >> q;
    vector<int> ar(n,k-q);
    rep(i,q){
        int s; cin >> s;
        ar[s-1]++;
    }
    rep(i,n){
        if (ar[i] > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}