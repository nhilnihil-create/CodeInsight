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
	double a,b,c;
	cin >> a >> b >> c;
	c = c * 3.14159265 / 180;
	cout << fixed << setprecision(8);
	cout << (double)(a*b*sin(c)/2) << endl;
	cout << (double)(a + b + sqrt(pow(a,2.0)+pow(b,2.0)-2*a*b*cos(c))) << endl;
	cout << (double)(b * sin(c)) << endl;
}