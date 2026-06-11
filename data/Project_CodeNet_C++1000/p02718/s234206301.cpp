#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi 3.14159265
#define oo 1000000007
#define loo 1000000000000000007

#define prime 1000000007

#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    ll v[n], tot = 0, aux = 0;
    for (int i = 0; i < n; ++i){
        cin >> v[i];
        tot+=v[i];
    }
    for (int i = 0; i < n; ++i){
        if(v[i]*4*m >= tot) aux++;
    }
    if( aux>=m) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}