#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    string s;
    cin >> s;
    
    bool x = true;
    rep(i, s.size()){
    if((i + 1) % 2 == 1 && s.at(i) != 'L') {
    continue;
    }
    else if((i + 1) % 2 == 0 && s.at(i) != 'R') {
    continue;
    }
    else {
    x = false;
    }
    }
    
    if(x) {
    cout << "Yes";
    }
    else {
        cout << "No";
    }

}