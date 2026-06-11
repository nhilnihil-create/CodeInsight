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

inline void solve(){
    int n,ans=0; cin>>n; 
    int  a[n], p = -1, ne = -1 ; 
    for (int i=0;i<n;i++){ 
        cin >> a[i] ; 
        ans += abs(a[i]) ; 
    } 
    sort(a,a+n); 
    if (a[n-1] < 0) { 
        ans += a[n-1]*2; 
        cout << ans << endl ; 
        p = a[n-1]; 
        for (int i=n-2;i>=0;i--){
            cout << p << " " << a[i] << endl;
            p = p - a[i] ; 
        }
    }
    else if (a[0]>0) {
        ans -= a[0]*2; 
        cout << ans << endl ; 
        ne = a[0] ; 
        for (int i=1;i<n-1;i++){
            cout << ne << " " << a[i] << endl;
            ne = ne - a[i];
        }
        cout << a[n-1] << " " << ne << endl;
    }
    else {
        cout << ans << endl ; 
        p = a[0];
        for (int i=1;i<n-1;i++){
            if (a[i]>=0){ 
                cout << p << " " << a[i] << endl; 
                p = p-a[i]; 
            }
        }
        cout << a[n-1] << " " << p << endl;
        p = a[n-1]-p;
        for (int i=1;i<n-1;i++){
            if (a[i]<0){ 
                cout << p << " " << a[i] << endl; 
                p = p-a[i]; 
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
