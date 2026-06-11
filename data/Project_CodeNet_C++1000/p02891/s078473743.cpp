#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    string s;
    ll K;
    int ans1 = 0;
    int ans2 = 0;
    cin >> s;
    cin >> K;

    int n = s.size();
    if (s == string(n, s[0])) {
        cout << n * K / 2 << endl;
        return 0;
    }

    for (int i = 0; i < n-1; i++) {
        if (s[i] == s[i+1]) {
            ans1++;
            i++;
        }
    }
    for (int i = 0; i+1<2*n;i++) {
        if (s[i%n]==s[(i+1)%n]) {
            ans2++, i++;
        }
    }
    cout << ans1 + (ans2-ans1)*(K-1) << endl;
}
