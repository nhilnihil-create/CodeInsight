#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
 
    int n,k;
    cin >> n >> k;
    
   vector<int> a(n);
    rep(i,n) {
    cin >> a.at(i);
    }
    
    int count = 0;
    
    rep(i,n) {
    if(a.at(i) >= k){
    count++;
    }
    }
    
    cout << count;
}