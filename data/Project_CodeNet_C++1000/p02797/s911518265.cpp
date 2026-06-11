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
	int n, k, s;
	cin >> n >> k >> s;
	int as = (s==1?2:s-1);
	REP(i, 0, k) cout << s << " ";
	REP(i, k, n) cout << as<< " ";

}
