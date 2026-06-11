#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef map<string, int> msi;
typedef pair<int, int> PII;

int main() {
    ll a;
    double b;
    cin >> a >> b;
    ll b_100 = b * 100 + 0.000001;

    cout << (a*b_100/100) << endl;
    return 0;
}