#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
int INF = 1001001001;

int main() {
    int a,b; cin >> a >> b;
    cout << max(a-2*b, 0) << endl;
    return 0;
}
