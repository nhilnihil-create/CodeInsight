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

int a = 1, b = 0, c, d, n, k = 0, ans = 0;
string s, t;
int mod = 1000000007;


int main()
{
	ll n, a, b;
	cin >> n >> a >> b;
	if ((b - a) % 2 == 0) {
		cout << (b - a) / 2 << endl;
	}
	else {
		cout << min(a-1,n-b)+1+(b-a-1)/2 << endl;
	}

	return 0;
}
