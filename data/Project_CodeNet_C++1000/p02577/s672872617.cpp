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
#define pff(a,b) printf("%d  %d\n",a,b);
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	string s;
	cin >> s;

	int sum = 0;
	rep(i, s.size()) {
		sum += s[i] - '0';
	}
	//cout << sum << endl;
	if (sum % 9==0)puts("Yes");
	else puts("No");

	return 0;
}