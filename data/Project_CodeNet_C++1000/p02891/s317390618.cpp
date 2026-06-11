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
    string s; int n,on=0,tw=0,th=0; 
    cin >> s >> n ; 
    string two=s+s,one=s,three=s+s+s;
    for (int i=0;i+1<sz(two);i++) {
        if (two[i]==two[i+1]){
            tw++;
            i++;
        }
    }
    for (int i=0;i+1<sz(one);i++) {
        if (one[i]==one[i+1]){
            on++;
            i++;
        }
    }for (int i=0;i+1<sz(three);i++) {
        if (three[i]==three[i+1]){
            th++;
            i++;
        }
    }
    if (sz(s)==1)
        cout << n/2 << endl;
    else if (on+tw==th)
        cout << (n/2*tw+(n&1)*on) << endl;
    else 
        cout << (tw-on)*(n-1)+on << endl;
} 

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0; 
}


/*

aaa

*/