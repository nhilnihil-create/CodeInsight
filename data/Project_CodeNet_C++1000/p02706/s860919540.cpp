#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <unordered_map>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <iomanip>
#define int long long 
#define lli unsigned long long int
#define pb push_back
#define ins emplace
#define mod 1e9+7
#define fi(i,n) for(int i=1; i<=n;i++)
#define INF 10000000000
#define unm  unordered_map<int , int>
#define vvi  vector<vector<int>>
#define sortall(v) sort(v.begin(),v.end())
#define deb(x)     cout << #x << "=" << x << endl
#define deb2(x,y)  cout << #x << "=" << x << "," << #y << "=" << y << endl
#define mp make_pair
#define F  first
#define S second
#define itr(it,a) for(auto it = a.begin(); it!=a.end();it++)
#define vi  vector<int>
#define pii pair<int ,int>
#define vii vector<vi>
#define in1(x) int x; cin >> x
#define in2(x,y) int x,y; cin >> x >> y;
#define in3(x,y,z) int x,y,z; cin >> x >> y >> z

using namespace std;
const int mx = 1e5;
vector<int> adj[mx] ;


int32_t main(){
	in2(n,m);
	vi v(m);
	int t =0 ;
	fi(i,m){
		int x ;cin >> x;
   		v.pb(x);   
	}
	for(auto i : v) {
		t+=i;

	}
	if( n-t>=0) cout << n-t << endl;
	else cout <<  "-1" << endl;
}
