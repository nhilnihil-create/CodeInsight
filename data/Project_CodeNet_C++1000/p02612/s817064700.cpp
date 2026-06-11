#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

int main(){
    int n;
    cin >> n;
    if (n % 1000 == 0) cout << 0 << endl;
    else cout << 1000 - (n % 1000) << endl;
}