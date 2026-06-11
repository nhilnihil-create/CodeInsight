#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18

vector<ll> lnln ;
void dfs(ll x, ll y){
    lnln.push_back(x) ;
    string s = to_string(x) ;
    ll f = s.size() ;
    if(f == y){
        return ;
    }
    char en = s[f - 1] ;
    string rr = s + en ;
    ll p = stoll(rr) ;
    for(ll j = -1; j <= 1 ; j++){
        if(en == '0' && j == -1){
            continue ;
        }
        else if (en == '9' && j == 1){
            continue ;
        }
        else {
            ll pf = p + j;
            dfs(pf, y) ;
        }
    } 
    return ;
}

int main() {
    ll k ;
    cin >> k ;
    for(ll i = 1; i <= 9; i++){
            dfs(i, 10) ;
    }
    sort(lnln.begin(), lnln.end()) ;
    cout << lnln[k - 1] << endl ;
}  