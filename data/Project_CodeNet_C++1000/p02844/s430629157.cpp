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

int one[10],two[10][10],three[10][10][10];

inline void solve() { 
    memset(one,0,sizeof(one));
    memset(two,0,sizeof(two));
    memset(three,0,sizeof(three));
    int n,ans=0; string  s ;  
    cin >> n >> s ; 
    for (int i=0;i<n;i++){
        int c=s[i]-'0'; 
        for (int j=0;j<10;j++){
            for (int k=0;k<10;k++){
                if (two[j][k]) three[j][k][c]=1;
            }
        }
        for (int j=0;j<10;j++){
            if (one[j]) two[j][c]++;
        }
        one[c]++;
    }
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            for (int k=0;k<10;k++){
                ans += three[i][j][k];
            }
        }
    }
    cout << ans << endl;
} 

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}

/*
5
23232

*/
