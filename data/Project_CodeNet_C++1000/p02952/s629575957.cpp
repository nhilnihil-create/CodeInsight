#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int ans = min(9,max(n,0))+min(900,max(n-99,0))+min(90000,max(n-9999,0));
    cout << ans << endl;
}
