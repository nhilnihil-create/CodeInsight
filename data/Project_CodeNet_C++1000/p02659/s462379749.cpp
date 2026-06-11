#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    ll A, B;
    string b;
    cin >> A >> b;
    B = 100*(b[0] - '0') + 10*(b[2] - '0') + (b[3] - '0');
    ll ans = A * B;
    ans /= 100;
    cout << ans << endl;
    return 0;
}