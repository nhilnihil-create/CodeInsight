#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    string s;
    cin >> s;
    int res;

    if(s == "SUN")
        res = 7;
    if(s == "MON")
        res = 6;
    if(s == "TUE")
        res = 5;
    if(s == "WED")
        res = 4;
    if(s == "THU")
        res = 3;
    if(s == "FRI")
        res = 2;
    if(s == "SAT")
        res = 1;

    cout << res << "\n";
}