#include <iostream>
#include <vector> 
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;

#define int long long

signed main() {
    string s;
    cin >> s;
    if(s[s.size() - 1] == 's') {
        cout << s + "es" << endl;
        return 0;
    }

    cout << s + "s" << endl;
    return 0;
}