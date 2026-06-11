#include <bits/stdc++.h>
using namespace std;
double pi = 2 * acos(0.0);
int main(){
        map<string, int> m;
        m["SAT"] = 1, m["SUN"] = 2, m["MON"] = 3; m["TUE"] = 4, m["WED"] = 5, m["THU"] = 6, m["FRI"] = 7;
        string s; cin >> s;
        if (m[s] >= 2) cout << 2 + (7-m[s]);
        else cout << 2 - m[s];
    return 0;
}

