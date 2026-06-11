#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    int k;
    cin >> k >> s;
    string sf;
    if (s.size() > k)
        sf = "...";
    cout << s.substr(0, k) + sf << "\n";
}
