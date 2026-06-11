#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
ll a,v,b,w,t;
cin >> a >> v >> b >> w >> t;

ll x = abs(b-a);
ll y = v-w;
if(y*t < x) cout << "NO" << endl;
else cout << "YES" << endl;
}
