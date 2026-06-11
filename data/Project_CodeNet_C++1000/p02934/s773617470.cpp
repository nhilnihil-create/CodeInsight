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
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int a = 1, b = 0, c, d, n, k = 0, ans = 0;
string s, t;
int mod = 1000000007;


int main()
{
	int n; cin >> n;
	vector<double> a(n); rep(i, n)cin >> a[i];
	int LCM=1;
	rep(i, n) { LCM = lcm(LCM, a[i]); }
	double sum = 0; rep(i, n) { sum += LCM / a[i]; }
	printf("%.8f\n", LCM/sum);

	return 0;
}
