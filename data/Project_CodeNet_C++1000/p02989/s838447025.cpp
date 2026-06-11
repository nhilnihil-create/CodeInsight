#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int main () {
    int n ;
    cin >> n ;
    vector<int> d(n) ;
    rep(i, n) cin >> d[i] ;
    sort(d.begin(),d.end()) ;
    int ub = n / 2 ;
    int lb = ub - 1 ;
    cout << d[ub] - d[lb] << endl ;
}



