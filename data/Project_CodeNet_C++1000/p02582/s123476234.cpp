#include <iostream>
#include <vector>
using namespace std;

#define int long long

signed main() {
    string s;
    cin >> s;

    if(s.find("RRR") != string::npos) {cout << 3 << endl; return 0;}
    else if(s.find("RR") != string::npos) {cout << 2 << endl; return 0;}
    else if(s.find("R") != string::npos) {cout << 1 << endl; return 0;}
    else {cout << 0 << endl; return 0;}
}