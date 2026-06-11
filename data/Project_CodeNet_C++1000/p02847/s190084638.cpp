#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;
#define INF 1001001001
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repX(i, n ,x) for (int i = x; i < (int)(n); ++i)
#define repBack(i, n) for (int i = n; i >= 0; --i)
#define dup(x,y) (((x)+(y)-1)/(y))

int main() {
    string S;
    cin >> S;
    if(S == "SUN")
        cout << 7 << endl;
    if (S == "MON")
        cout << 6 << endl;
    if (S == "TUE")
        cout << 5 << endl;
    if (S == "WED")
        cout << 4 << endl;
    if (S == "THU")
        cout << 3 << endl;
    if (S == "FRI")
        cout << 2 << endl;
    if (S == "SAT")
        cout << 1 << endl;

    return 0;
}