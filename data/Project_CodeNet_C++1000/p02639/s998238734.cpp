#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const int mod = 1e9 + 7;

int main(){
    vector<int> x(5);
    for (int i = 0; i < 5; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < 5; ++i) {
        if (x[i] == 0) cout << i+1 << endl;
    }
}