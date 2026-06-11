#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    string s;
    cin >> s;
    
    string t = s;
    reverse(t.begin(), t.end());
    int count = 0;
    rep(i,s.size()) {
     if(s.at(i) != t.at(i)) {
     count++;
     }
    }
    cout << count / 2;
    
}