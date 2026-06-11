#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long double a;
    long double b;

    cin >> a >> b;
    b = (long long int) (b * 100 + 0.001);
    cout << (long long int) (a * b/100) << endl;
    return 0;
}