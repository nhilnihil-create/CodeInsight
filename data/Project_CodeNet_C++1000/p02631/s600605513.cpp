#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//print(fixed << setprecision(10));
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define repk(i,n,k) for(ll i = k; i < (n); i++)
#define all(n) n.begin(), n.end()
#define print(n) cout << n << endl
double PI = acos(-1.0);
int INF = 1e9;
ll LINF = 1e18;
ll MOD = 1e9+7;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,num=0;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        num ^= a[i];
    }
    rep(i,n) print((num^a[i]));
    return 0;
}