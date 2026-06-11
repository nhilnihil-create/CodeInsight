#include <bits/stdc++.h>

#define tc(t) int t; cin>>t; while(t--)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    if (s == "SUN") cout << "7" << endl;
    else if (s == "MON") cout << "6" << endl;
    else if (s == "TUE") cout << "5" << endl;
    else if (s == "WED") cout << "4" << endl;
    else if (s == "THU") cout << "3" << endl;
    else if (s == "FRI") cout << "2" << endl;
    else cout << "1" << endl;


}




