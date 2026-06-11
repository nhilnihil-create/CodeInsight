#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

int main(){
    ll m;
    cin >> m;
    ll digit = 0;
    ll sum = 0;
    ll d, c;
    for (int i = 0; i < m; ++i) {
        cin >> d >> c;
        digit += c;
        sum += d*c;
    }
    cout << (digit - 1) + ((sum - 1) / 9) << endl;
}