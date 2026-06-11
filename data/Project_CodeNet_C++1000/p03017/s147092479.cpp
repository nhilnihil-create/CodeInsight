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

inline void solve(){
    int n,a,b,c,d; 
    cin>>n>>a>>b>>c>>d;
    a--,b--,c--,d--;
    string s; cin>>s; 
    bool ok=true;
	for (int i=a+1,has=0;i<c;i++){ 
	    if (s[i]=='.') has=0;
	    else has++;
	    if (has>=2) ok=false; 
	}
	for (int i=b+1,has=0;i<d;i++){ 
	    if (s[i]=='.') has=0;
	    else has++;
	    if (has>=2) ok=false; 
	}
    if (c>d ){ 
    	int hs=0; 
    	for (int i=b-1,has=0,dot=0;i<=d+1;i++){ 
    		if (s[i]=='.') dot++,has=0; 
    		else dot=0,has++;  
    		if (has>=2) break; 
    		hs=max(hs,dot); 
    		if (hs>=3) break;
    	} 
    	if (hs<3) ok=false;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
