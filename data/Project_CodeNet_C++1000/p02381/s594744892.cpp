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
	int n[100] = {0};
	int s[1000][1000] = {0};
	double a[100] = {0};
	double m[100] = {0};
	int i = 0;
	do{
		cin >> n[i];
		for(int j = 0; j < n[i]; j++){
			cin >> s[i][j];
			m[i] += s[i][j];
		}
		m[i] /= n[i];
		for (int j = 0; j < n[i]; ++j)
		{
			a[i] += pow(s[i][j] - m[i],2.0);
		}
		a[i] = sqrt(a[i]/n[i]);
		i++;
	}while(n[i-1] != 0);
	i = 0;
	do{
		cout << fixed << setprecision(8);
		cout << a[i] << endl;
		i++;
	}while(n[i] != 0);
}