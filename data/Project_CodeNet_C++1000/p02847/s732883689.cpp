#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >>s ;
    if(s == "SUN") cout << 7 << endl;
    else if(s == "MON") cout << 6 << endl;
    else if(s == "TUE") cout << 5 << endl;
    else if(s == "WED") cout << 4 << endl;
    else if(s == "THU") cout << 3 << endl;
    else if(s == "FRI") cout << 2 << endl;
    else if(s == "SAT") cout << 1 << endl;
    return 0;
}