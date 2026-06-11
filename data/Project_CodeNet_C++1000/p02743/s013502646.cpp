//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000010;
const ll LOG = 25;


int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll a, b, c; cin >> a >> b >> c;
  bool ok;
  if (a+b>=c) ok = false;
  else {
    if (4*a*b<(c-a-b)*(c-a-b)) ok = true;
    else ok = false;
  }
  cout << (ok? "Yes" : "No") << endl;










	return 0;
}
