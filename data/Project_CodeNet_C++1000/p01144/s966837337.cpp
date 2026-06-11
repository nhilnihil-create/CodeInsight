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
#define pi 3.14159265359
#define shosu(X) fixed << setprecision(X)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
	int n,m;
	while(1){
		cin >> n >> m;
		vector<pair<int,int> > data;
		if(n==0&&m==0) break;
		REP(i,n){
			int tmp1,tmp2;
			cin >> tmp1 >> tmp2;
			data.pb(make_pair(tmp2,tmp1));
		}
		sort(All(data));
		ll int ans = 0;
		for(int i=n-1;i>=0;i--){
			if(m>data[i].second) m-=data[i].second;
			else if(m<=data[i].second){
				ans+= (data[i].second-m)*data[i].first;
				m = 0;
			}
		}
		cout << ans << endl;
	}
}