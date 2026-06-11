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
    
    int sum = 0;
    rep(i,n) {
     rep(j,n){
         if(i == j){
         continue;
         }
     sum += a.at(i) * a.at(j);
     }
    }
    
    cout << sum / 2;
    
}