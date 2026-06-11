#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 998244353;


int main() {
    int h1, m1, h2, m2, k; 
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int t1 = 60*h1+m1, t2=60*h2+m2;
    if (t1 >= t2) t2 += 60*24;
    int ret = max(t2 - t1 - k, 0);
    cout << ret << endl;
    return 0;
}