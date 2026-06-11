#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    
    for (int i = 0; i < n; i++) {
        cout << s[i] << t[i];
    }
    cout << "\n";
}
