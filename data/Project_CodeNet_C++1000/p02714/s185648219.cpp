#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    string s;
    cin >> n >> s;

    ll r = 0, g = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') r++;
        else if (s[i] == 'G') g++;
        else if (s[i] == 'B') b++;
    }

    ll sum = r * g * b;
    ll ex = 0;
    for (int i = 0; i < n; i++) {
        for (int m = 1; i + 2 * m < n; m++) {
            if (s[i] != s[i+m] && s[i] != s[i+2*m] && s[i+m] != s[i+2*m]) ex++;
        }
    }

    cout << sum - ex << endl;
}
