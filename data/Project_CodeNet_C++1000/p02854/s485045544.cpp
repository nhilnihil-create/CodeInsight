#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>	
#include <cmath>
#include <string>
#include<math.h>
#include<sstream>//���炵���̂Œ���
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define Cout(s) cout<<s<<endl
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
string Yes(bool b) { if (b) { return "Yes"; } else { return "No"; } }
string YES(bool b) { if (b) { return "YES"; } else { return "NO"; } }
//================================================
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

ll a = 1, b = 0, c, d, n, k = 0, ans = 0;
string s, t;
int mod = 1000000007;


int main()
{
	int n; cin >> n; vector<ll> a(n);cin>> a[0];
	rep(i, n - 1) { cin >> b; a[i + 1] = a[i] + b; }
	ll sum = a[n - 1]; ll  flag = sum / 2;
	for(int i=1;i<n;i++) {
		if (flag <= a[i]&&flag>a[i-1]) {
			cout << min(abs(sum - 2*a[i]),abs (sum - 2*a[i-1])) << endl; return 0;
		}
	}


	return 0;
}
