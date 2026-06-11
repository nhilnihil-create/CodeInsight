#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;
#define INF	100000000
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
#define lb lower_bound
#define ub upper_bound
#define SS stringstream
#define rep(i,n) for(int i = 0; i < n; i++)
#define SORT(x) sort((x).begin(), (x).end())
#define clr(a,b) memset((a),(b),sizeof(a))
typedef long long int ll;
typedef pair<int, int> P;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<P> Vp;
typedef priority_queue<P, vector<P>, greater<P> > PQ;

int table[100000];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin >> n,n){
		rep(i,100000) table[i] = 0;
		rep(i,n){
			char t;
			int a,b,c,d,e,f;
			cin >> a >> t >> b >> t >> c >> d >> t >> e >> t >> f;
			c += a*3600+b*60;
			f += d*3600+e*60;
			table[c]++;
			table[f]--;
		}
		for(int i = 1; i < 100000; i++) table[i] += table[i-1];
		int ans = 0;
		rep(i,100000) ans = max(ans,table[i]);
		cout << ans << endl;
	}
}