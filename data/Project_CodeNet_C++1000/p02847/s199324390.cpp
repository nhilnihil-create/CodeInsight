#include <bits/stdc++.h>
using namespace std;

signed main() {
    int i;
    char date[7][4] = {
        "SAT",
        "FRI",
        "THU",
        "WED",
        "TUE",
        "MON",
        "SUN"
    };
    string s;
    
    cin >> s;
    
    i = 0;
    while ( s != date[i] ) {
        i++;
    }
    
    cout << i + 1 << endl;
    return (0);
}