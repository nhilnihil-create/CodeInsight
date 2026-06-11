#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define p(t1,t2) pair<t1,t2>
using namespace std ;
int main(){
    ll x , k , d ;
    cin >> x >> k >> d ;
    x = abs(x) ;
    ll mov = (x - x%d) / d;
    if(k>mov) cout << ((k-mov)%2)*(abs(x%d-d)) + ((k-mov+1)%2)*(abs(x%d)) << "\n" ;
    else cout << x - k*d << "\n" ;
    return 0 ;
}