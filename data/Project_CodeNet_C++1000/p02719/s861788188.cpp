#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef map<string, int> msi;

int main(){
    ll n, k; cin >> n >> k;
    ll ans_1 = n % k, ans_2 = abs(n % k - k);
    cout << min(ans_1, ans_2) << endl;
    return 0;
}
