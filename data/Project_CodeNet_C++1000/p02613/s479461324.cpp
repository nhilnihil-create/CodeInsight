#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define eps 1e-9
#define inf 0x3f3f3f
#define mod 4999999
using namespace std;

int main() {
	speed;
    int n,a = 0,w = 0,t = 0,r = 0;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s == "AC")
            a++;
        else if (s == "TLE")
            t++;
        else if (s == "WA")
            w++;
        else
            r++;
    }
    cout << "AC x " << a << "\nWA x " << w << "\nTLE x " << t << "\nRE x " << r;
}