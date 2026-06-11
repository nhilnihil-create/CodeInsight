#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll lg=31;
const ll N=1e5+5;
const ll INF=3e18;
const ll mod=1e9+7;
const double PI = 3.14159265358979323846;

#define f first
#define s second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repp(i, a, b) for(int i = a; i > (b); --i)
#define sz(x) (int)(x).size()
#define pb push_back
#define GCD(a,b) __gcd((a),(b))
#define all(v) v.begin(),v.end()
#define LCM(a,b) ((a)*(b))/GCD((a),(b))
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
	FASTIO;
	int n;
	cin >> n;
	vector<vector<int>> v;
	for (int i = 0; i < n; i++) {
	    int a, b;
	    cin >> a >> b;
	    vector<int> v1;
	    v1.push_back(a);
	    v1.push_back(b);
	    v.push_back(v1);
	}
	bool flag = false;
	for (int i = 0; i < n - 2; i++) {
	    if (v[i][0] != v[i][1]) {
	        continue;
	    }
	    bool poss = true;
	    for (int j = i + 1; j <= i + 2; j++) {
	        if (v[j][0] != v[j][1]) {
	            poss = false;
	            break;
	        }
	    }
	    if (poss) {
	        flag = true;
	        cout << "Yes" << endl;
	        break;
	    }
	}
	if (!flag) {
	    cout << "No" << endl;
	}
	return 0;
}