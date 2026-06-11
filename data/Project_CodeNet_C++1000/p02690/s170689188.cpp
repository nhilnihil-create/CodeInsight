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

int fun(int n){
	return (n*n*n*n*n);
}

inline void solve(){
    int x;cin>>x;
    for (int i=0;i<500;i++){
    	for (int j=0;j<500;j++){
    		if (fun(i)-fun(j)==x) {
    			cout << i << " "<<j<<endl;
    			return;
    		}
    		if (fun(i)-fun(-j)==x) {
    			cout << i << " "<<-j<<endl;
    			return;
    		}if (fun(-i)-fun(j)==x) {
    			cout << -i << " "<<j<<endl;
    			return;
    		}
    	}
    }
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
/*

*/
