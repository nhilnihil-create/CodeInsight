/*input
10
5 3
5 7
8 9
1 9
9 10
8 4
7 4
6 10
7 2
*/
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <iomanip>
 
using namespace std; 
 
int GCD(int x,int y){return y?GCD(y,x%y):x;}
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,n) for(int i=0;i<(n);i++)
#define repl(i,a,b) for(int i=(a);i<(b);i++)
#define repm(i,a,b) for(int i=(a);i>(b);i--)
#define rept(v) for(auto it=v.begin();it<v.end();it++)
#define all(v) v.begin(),v.end()
const int INF = 1<<30;
typedef long long ll;
typedef pair<int,int> pii;
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	ll ans=0;
	repl(i, 1, n+1) ans+=i*(n-i+1);
	rep(i, n-1) {
		ll u,v;
		cin >> u >> v;
		if(u>v) swap(u, v);
		ans-=u*(n-v+1);
	}
	cout << ans;
	return 0;
}