#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
   int n;
   cin >> n;
   
   vector<double> a(n);
   rep(i,n) {
    cin >> a.at(i);
    }
    
    double x;
    
    rep(i, n) {
    x += 1 / a.at(i);
    }
    
    cout << 1 / x;
}