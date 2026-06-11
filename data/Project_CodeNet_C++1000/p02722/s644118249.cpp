#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;
 
const int INF = 1e9;
const int MOD = 1e9+7;
const double EPS = 1.0e-12;
const double PI = acos(-1.0);

vector<ll> divsor(ll n) {
    vector<ll> res;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i * i != n) res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
	ll n;
	cin >> n;
	ll ans = divsor(n-1).size()-1;
	for(auto x : divsor(n)){
		ll tmp = n;
		if(x == 1) continue;
		while(tmp%x == 0) tmp /= x;
		if(tmp%x == 1) ans++; 
	}
	cout << ans << endl;
    
	return 0;
}