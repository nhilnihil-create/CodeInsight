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
    int  a, b, ticket ,f=1000000,s=1000000; 
    cin >> a >> b >> ticket ; 
    vi  A(a),B(b);
    for (int &i: A) {
        cin>>i; 
        f = min(f,i);
    }
    for (int &i: B) {
        cin>>i; 
        s = min(s,i);
    }
    int ans=1000000;
    while (ticket--){
        int a,b,c;
        cin >> a >> b >> c ; 
        a--,b--;
        ans = min(A[a]+B[b]-c,ans);
    }
    cout << min(ans,f+s) << endl;
    
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
