#include <bits/stdc++.h>
using namespace std;

//const long double PIL = 3.141592653589793238462643383279502884L;
//const double PI = 3.14159265358979323846;

#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define what_is(x) cerr << #x << " is " << x << endl;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vll = vector<long long>;
using vii = vector<pair<int,int>>;

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);
	int x[2];
	cin >> x[0] >> x[1];
	int answer = 0;
	for (int i = 0; i < 2; i++) {
		if (x[i] == 1)
			answer += 300000;
		else if (x[i] == 2)
			answer += 200000;
		else if (x[i] == 3)
			answer += 100000;
	}
	if (x[0] == 1 && x[1] == 1) answer += 400000;
	cout << answer << endl;
}
