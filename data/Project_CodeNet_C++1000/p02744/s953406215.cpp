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

void  fun(char c,string s,int n) { 
	if (n==0) { 
		cout << s << endl; 
		return; 
	} 
	for (char i='a';i<=c;i++){ 
		fun(max(c,(char)(i+1)),s+i,n-1); 
	} 
} 
 
inline void solve(){ 
    int n; cin>>n; 
    fun('a',"",n); 
    return; 
} 

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
