#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
using PL = pair<ll , ll> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

string dfs(ll x){
    if(x == 0){
        return "" ;
    }
    x-- ;
    return dfs(x/26) + string(1, 'a' + x%26) ;
}


int main(){
    ll n ;
    cin >> n;
    cout << dfs(n) << endl ;
}

