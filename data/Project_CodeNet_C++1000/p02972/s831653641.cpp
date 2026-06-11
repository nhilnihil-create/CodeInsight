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
    int n; cin>>n; 
    vi a(n+1),res(n+1,0); 
    for (int i=1;i<=n;i++) cin>>a[i]; 
    for(int i=n;i>0;i--){
        int sum=0;
        for (int j=i+i;j<=n;j+=i){
            sum += res[j];
        }
        if (sum%2 != a[i]) res[i]=1;
    }
    int c=0;
    for (int i=1;i<=n;i++) c+=res[i];
    cout << c << endl;
    for (int i=1;i<=n;i++) if(res[i]) cout<< i <<endl;
    cout << endl;
} 

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
