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
#include <functional>
#define   mod  (int)1e9+7
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi   vector<int> 
#define   co(x)  cout << x << '\n' 
#define   dbg(x)  cerr << #x << " = " << x << '\n' 
#define   bitcount(x)  (int)__builtin_popcount(x) 
#define   sz(x)  (int)x.size()
#define   all(a) a.begin(),a.end() 
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std ; 

int bigmod(int a, int p, int m) { 
    if (p == 0)  return (1 % m) ; 
    if (p & 1){ 
        int p1 = a % m ;
        int p2 = bigmod( a, p-1, m ) ; 
        return  (p1 * p2) % m ; 
    } 
    int p1 = bigmod( a, p/2, m ) ; 
    return  (p1 * p1) % m ; 
}

string  s ; 
int dp[100005][13] ; 
int p[100005];


int fun(int idx,int num) { 
    if (idx == sz(s)) { 
        return ( num == 5 ) ; 
    }
    if (dp[idx][num] >= 0) return  dp[idx][num] ; 
    int sum = 0 ; 
    if (s[idx] == '?') { 
        for (int i=0;i<=9;i++) { 
            int x = (num + (i * p[idx])) % 13 ; 
            sum += fun(idx+1, x) ; 
        } 
    } 
    else { 
        int x = (num + ((s[idx]-'0') * p[idx])) % 13 ;
        sum = fun(idx+1, x) ; 
    }
    sum %= mod;
    return  dp[idx][num] = sum ; 
} 

// 002005 ??2??5


signed main() 
{ 
    memset(dp,-1,sizeof(dp)) ; 
    for (int i=0;i<=100000;i++) p[i] = bigmod(10,i,13) ; 
    cin >> s ; 
    reverse(s.begin(), s.end()) ; 
    cout << fun(0,0) << endl ; 
    return 0; 
} 
