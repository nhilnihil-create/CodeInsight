#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pf(n) printf("%d\n",n)
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	int n, m;
	cin >> n >> m;
	vector<bool> prob(n, false);
	vector<int> w(n);
	int wa = 0;
	int ac = 0;
	rep(i, m) {
		int p;
		string s;
		cin >> p >> s;
		p--;
		if (prob[p]) continue;
		if (s == "AC") {
			prob[p] = true;
			ac++;
		}
		else {
			w[p]++;
		}
		
	}
	rep(i,n){
		if (prob[i]) wa += w[i];
	}

	pf(ac);
	pf(wa);

	return 0;
}