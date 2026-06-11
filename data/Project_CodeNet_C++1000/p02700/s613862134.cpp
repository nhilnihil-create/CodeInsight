#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string ans = "No";

    int x = c/b, y = a/d;
    if (c%b != 0) {
        x ++;
    }
    if (a%d != 0) {
        y ++;
    }
    if (x <= y) {
        ans = "Yes";
    }
    cout << ans << endl;
}