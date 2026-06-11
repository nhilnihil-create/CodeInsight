#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	ll ans = c - a - b;
	if(ans > 0 && ans*ans > 4*a*b) cout << "Yes";
	else cout << "No";

}
