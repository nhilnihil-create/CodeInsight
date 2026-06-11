#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    set<string> s;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size();

    return 0;
}