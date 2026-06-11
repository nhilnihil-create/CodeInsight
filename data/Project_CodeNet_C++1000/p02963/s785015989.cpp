#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

const int lim = 1000000007;

int main(){
    ll S;
    cin >> S;

    const int val = pow(10, 9);

    int y = (S + val - 1) / val;
    int x = val * y - S;

    cout << 0 << " " << 0 << " " << val << " " << 1 << " " << x << " " << y << endl;
    return 0;
}