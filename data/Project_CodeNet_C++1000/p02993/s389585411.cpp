#include <bits/stdc++.h>
using namespace std;


int main() {
    char cur, prev = '.';
    bool ans = 1;
    for(int i=0; i<4; i++) {
        cin >> cur;
        if(cur == prev) {
            ans = 0;
        }
        prev = cur; 
    }
    cout << (ans ? "Good" : "Bad") << "\n";
}
