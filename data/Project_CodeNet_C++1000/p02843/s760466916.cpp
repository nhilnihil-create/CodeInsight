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
#define   ff   first
#define   ss   second
#define   pii  pair<int,int>
using namespace std;

inline void solve(){
    int n; cin>>n; 
    int rem=n%100,ans=0;
    while (rem>0){
        if (rem>=5) ans += 105, rem -= 5;
        else if (rem>=4) ans += 104, rem -= 4;
        else if (rem>=3) ans += 103, rem -= 3;
        else if (rem>=2) ans += 102, rem -= 2;
        else ans += 101, rem -= 1;
    }
    if (ans>n) cout << 0 << endl;
    else cout << 1 << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
