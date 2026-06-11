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
	long double ave;
	long double sum = 0;
	int n;
	long double ans;
	long double data[1000];
	while(1){
		cin >> n;
		sum = 0;
		if(n==0) break;
		REP(i,n){
			cin >> data[i];
			sum += data[i];
		}
		ave = sum / (long double) n;
		ans = 0;
		REP(i,n){
			ans += (data[i] - ave) * (data[i] - ave) / (long double) n;
		}
		cout << setprecision(20) << fixed << sqrt(ans) << endl;
	}
}