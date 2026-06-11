#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

using ll = long long;

#define INF 2e9; //Integer Infinity
#define LINF 2e18; //Long Long Integer Infinity
#define MOD 1000000007; //Too Large Pure Number
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)//Loop i to n(i=0)
#define all(x) (x).begin(),(x).end();//for sort
#define dump(x) cout << #x << " = " << (x) << endl;//for debug 
#define YES(b) cout << ((n)?"YES":"NO") << endl;//print "YES" or "NO"
#define Yes(b) cout << ((n)?"Yes":"No") << endl;//print "Yes" or "No"

#define PI 3.141592653589793;

int main(void) {
	int n,out=0;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		if (i < 10 || (i >= 100 && i <= 999) || (i >= 10000 && i <= 99999))out++;
	}
	cout << out << endl;
	return 0;
}