#include <bits/stdc++.h>
using namespace std;

signed main() {
    string s;
    cin >> s;
    
    if ( s == "Sunny" ) {
        cout << "Cloudy\n";
    } else if ( s == "Rainy" ) {
        cout << "Sunny\n";
    } else {
        cout << "Rainy\n";
    }
    return (0);
}