#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
    ll int a, b, c;
    cin >> a >> b >> c;
    ll int small = 4*a*b;
    ll int large = (c-a-b)*(c-a-b);
    if(small < large && c-a-b > 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    // ll int d = c-a-b;
    // if (d > 0 and a * a + b * b + c * c > 2 * a * b + 2 * a * c + 2 * b * c) {
    //      cout << "Yes" << endl;
    //  } else {
    //      cout << "No" << endl;
    //  }

    // cout << "small:" << small << " large:" << d*d << " c-b-a:" << c-b-a << endl;

    return 0;
}
