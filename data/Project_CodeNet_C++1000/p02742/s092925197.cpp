#include <bits/stdc++.h>
#include <math.h>

#define PI 3.14159265358979323846264338327950L
#define ll long long
#define lli long long int

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
        ll h, w;
        cin >> h >> w;
        if (h == 1 || w == 1) {
            cout << 1 << "\n";
        } else {
            if (h * w % 2 == 0) {
                cout << h * w / 2 << "\n";
            } else {
                cout << h * w / 2 + 1 << "\n";
            }
        }
    return 0;

}
