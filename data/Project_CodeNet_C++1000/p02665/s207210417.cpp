#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <iomanip>  //setprecision(桁)
using namespace std;
#define pb push_back
#define rep(i,n) for(int i = 0;i < n;i++)
#define INF 1e+9
#define ll long long int

int main(){
    int n; cin >> n;
    vector<ll> a(n+1),b(n+1);
    rep(i,n+1) cin >> a[i];
    
    if(n == 0){
        if(a[0] == 1){cout << 1 << endl; return 0;}
        else {cout << -1 << endl; return 0;}
    }
    if(a[0] != 0) {cout << -1 << endl; return 0;}
        
    

    
    for(int i = n-1; i >= 0; i--){
        b[i] = b[i+1] + a[i+1];
    }

    b[0] = 1; b[n] = a[n];
    for(int i = 1; i < n + 1; i++){
        b[i] = min(b[i], 2 * b[i-1] - a[i]); //cout << b[i] << endl;
        if(b[i] < 0){cout << -1 << endl; return 0;}
    }
    
    if(b[n] < 0){cout << -1 << endl; return 0;}
    
    ll ans = 0;
    rep(i,n+1) ans += a[i];
    rep(i,n) ans += b[i]; //cout << b[i] << endl;}
    cout << ans << endl;
}
