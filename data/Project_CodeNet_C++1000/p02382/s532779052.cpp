#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <complex>
using namespace std;
 
#define ll long long
#define vvi vector< vector<int> >
#define vi vector<int>
#define All(X) X.begin(),X.end()
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
	int n;
	double x[2][100] = {0};
	double d[5] = {0};
	cin >> n;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> x[i][j];
		}
	}
	cout << fixed << setprecision(8);
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			d[i] += pow(sqrt(pow(x[0][j] - x[1][j], 2.0)), (double)i);
		}
		d[i] = pow(d[i], 1.0/i);
		cout << d[i] << endl;
	}
	for (int i = 0; i < n; ++i)
	{
		if(d[4] < sqrt(pow(x[0][i] - x[1][i], 2.0))){
			d[4] = sqrt(pow(x[0][i] - x[1][i], 2.0));
		}
	}
	cout << d[4] << endl;
}