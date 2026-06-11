#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    string t;
    cin >> t;
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        if(s.at(i)==t.at(i))ans++;
    }
    cout << ans <<endl;
}