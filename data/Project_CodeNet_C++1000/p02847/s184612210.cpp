#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    string s;
    int ans;
    cin >> s;
    if (s == "SUN") {
        ans = 7;
    } else if (s == "MON") {
        ans = 6;
    } else if (s == "TUE") {
        ans = 5;
    } else if (s == "WED") {
        ans = 4;
    } else if (s == "THU") {
        ans = 3;
    } else if (s == "FRI") {
        ans = 2;
    } else if (s == "SAT") {
        ans = 1;
    }
    cout << ans << endl;
    return 0;
}