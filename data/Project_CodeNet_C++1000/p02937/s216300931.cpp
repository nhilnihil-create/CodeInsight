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
#include <list>
#include <stack>
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

vector <vi> dp(26,vi(100005));
int n;

int fun(int l,int r){
	if (r<l)  return  r+(n-l+1); 
	else  return  (r-l+1); 
}

inline void solve(){ 
    string  s, t; 
    cin >> s >> t ; 
    n = sz(s);
    vi oc(26,0); 
    for (int i=0;i<n;i++) { 
    	oc[s[i]-'a']++ ; 
    	dp[s[i]-'a'][i+1] = i+1 ; 
    } 
    for (int i=0;i<sz(t);i++) { 
    	if (oc[t[i]-'a'] == 0) { 
    		cout << "-1" << endl ; 
    		return ; 
    	} 
    } 
    for (int i=0;i<26;i++){ 
    	for (int j=n-1;j>=0;j--) 
    		if ( !dp[i][j] )  dp[i][j] = dp[i][j+1]; 
    	dp[i][n+1]= dp[i][0]; 
    	for (int j=n;j>=0;j--) 
    		if ( !dp[i][j] ) dp[i][j] = dp[i][j+1]; 
    } 
    int ans=0; 
    for (int  i=0, idx= 1 ; i < sz(t) ; i++ ){ 
    	int  p = dp[t[i]-'a'][idx] ; 
    	ans += fun(idx,p); 
    	idx = p+1; 
    } 
    cout << ans << endl; 
} 

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}