#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const int mod = 1e9 + 7;

int main(){
    ll a;
    cin >> a;
    ll ba, bb;
    scanf("%lld.%lld", &ba, &bb);
    cout << (a * (ba * 100 + bb)) / 100 << endl;
}