#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#include <numeric>
using namespace std;

int main() {
 long long n, k, q;
 cin >> n >> k>>q;
    
 vector<long long> v(q);
 rep(i,q) {
  cin >> v.at(i);
 }
    
    vector<long long> point(n);
    for(int i =0; i<n; i++) {
    point.at(i) = k - q;
    }
    
    rep(i,q) {
     point.at(v.at(i) - 1) += 1;
    }
    
    rep(i,n) {
     if(point.at(i) > 0) {
      cout << "Yes" << endl;
     } else {
      cout << "No" << endl;;
     }
    }
}