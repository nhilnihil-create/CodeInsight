#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repab(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define pb push_back
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
#define endl "\n"

typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int INF = 1001001001;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};

//--//--//--//--//--//--//--//--//--//--//--//

int main(){

	//input//
	int n;
	cin >> n;
	vec<int> a(n);
    vec<int> b(n);
	rep(i, n){
		int x, y;
		cin >> x >> y;
		a.at(i) = x - y;
		b.at(i) = x + y;
	}
	sort(all(a));
	sort(all(b));

	cout << max(a.at(n-1)-a.at(0), b.at(n-1)-b.at(0)) << endl;

	return 0;
}