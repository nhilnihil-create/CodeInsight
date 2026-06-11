#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
 int n;
 cin >> n;
 
 vector<int> a(n);
 rep(i,n) {
  cin >> a.at(i);
 }
    vector<int> b(n);
    rep(i,n) {
     b.at(i) = a.at(i);
    }
    
    int semimax = 0;
    sort(b.begin(),b.end(),greater<int>());
    int maxa = b.at(0);
        if(b.at(0) != b.at(1)) {
         semimax = b.at(1);
        }
        
    if(b.at(0) == b.at(1)) {
     rep(i,n) {
      cout << maxa << endl;;
     }
    }
    else {
        rep(i,n) {
         if(a.at(i) == maxa) {
         cout << semimax << endl;
         }
            else {
             cout << maxa << endl;
            }
        }
        
     }
    
    
}