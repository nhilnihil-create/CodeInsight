#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    ll n;
    cin >> n;
    ll a[n];
    ll s=0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    ll minx = s, sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += a[i];
        minx = min(minx, abs(sum - (s - sum)));
    }

    cout << minx << endl;

    return 0;
}