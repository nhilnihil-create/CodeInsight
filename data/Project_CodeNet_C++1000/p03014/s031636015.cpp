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

int x[2005][2005],y[2005][2005];

inline void solve(){
    int  r, c ; 
    cin >> r >> c ; 
    string s[r];
    for (int i=0;i<r;i++){
        cin >> s[i] ; 
        for (int j=0,cnt=0;j<c;j++){
            if (s[i][j]=='#') {
                x[i][j] = -1; 
                cnt = 0;
            }
            else {
                cnt++; 
                x[i][j] = cnt;
            }
        }
    }
    for (int i=0;i<c;i++){
        for (int j=0,cnt=0;j<r;j++){
            if (s[j][i] == '#') {
                y[j][i] = -1 ; 
                cnt = 0 ; 
            }
            else {
                cnt++; 
                y[j][i] = cnt ; 
            }
        }
    }
    for (int i=0;i<r;i++){
        for (int j=c-2;j>=0;j--){
            if (x[i][j] != -1){
                x[i][j] = max(x[i][j],x[i][j+1]);
            }
        }
    }
    for (int i=0;i<c;i++){
        for (int j=r-2;j>=0;j--){
            if (y[j][i] != -1){
                y[j][i] = max(y[j][i],y[j+1][i]);
            }
        }
    }
    int ans = 0;
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            ans = max(ans,x[i][j]+y[i][j]-1);
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
