#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ll a, bb; string s;
    cin >> a >> s;
    bb = stoll(s.erase(1, 1));
    cout << a * bb / 100 << endl;
    return 0;
}