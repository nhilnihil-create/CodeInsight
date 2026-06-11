#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
 int n;
 cin >> n;
 
    vector<int> d(n);
    rep(i,n) {
     cin >> d.at(i);
    }
    
    sort(d.begin(),d.end());
    int mid = d.at(n/2-1);
    
    if(d.at(n/2) == mid) {
     cout << 0;
    }
    else {
        cout << d.at(n/2) - d.at(n/2-1);
    }
}