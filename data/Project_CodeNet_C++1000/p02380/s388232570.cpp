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

#define shosu(X) setprecision(X) << fixed
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
	long double a,b,c;
	cin >> a >> b >> c;
	/*to radian*/
	c = M_PI *c / 180;
	cout << shosu(20) << a*b*sin(c)/2<< endl;;
	long double tmp = sqrt(a*a+b*b-2*a*b*cos(c));
	cout << a+b+tmp << endl;;
	cout << b*sin(c) << endl;
}