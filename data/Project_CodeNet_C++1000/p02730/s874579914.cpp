#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    string s1 = s.substr(0,(s.size()-1)/2);
    string s2 = s.substr((s.size()+3)/2-1,(s.size()-1)/2);
    string sr = s, s1r = s1, s2r = s2;
    reverse(sr.begin(),sr.end());
    reverse(s1r.begin(),s1r.end());
    reverse(s2r.begin(),s2r.end());
    if (s == sr && s1 == s1r && s2 == s2r) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}