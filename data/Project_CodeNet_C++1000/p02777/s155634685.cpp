#include <bits/stdc++.h>
using namespace std;
double pi = 2 * acos(0.0);
int main(){
        map<string, int> m;
        string s1, s2;
        int x1, x2;
        cin >> s1 >> s2 >> x1 >> x2;
        m[s1] = x1, m[s2] = x2;
        string t; cin >> t;
        m[t]--;
        cout << m[s1] << " " << m[s2];
    return 0;
}

