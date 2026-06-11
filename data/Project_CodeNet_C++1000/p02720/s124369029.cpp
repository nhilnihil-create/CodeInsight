/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   all(a) (a.begin(),a.end())
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

vector <int> ans;

void fun(int pre,int post,int num,int in){
	if (in==10) return;
	for (int i=pre;i<=post;i++){
		int h=num*10+i;
		ans.pb(h);
		fun(max(0LL,i-1),min(i+1,9LL),h,in+1);
	}
}

inline void solve(){
	ans.pb(0);
	fun(1,9,0,0);
	sort(ans.begin(),ans.end());
	int n; cin>>n;
	cout << ans[n] << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
