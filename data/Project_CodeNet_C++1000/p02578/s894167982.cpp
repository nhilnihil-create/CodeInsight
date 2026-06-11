#include <bits/stdc++.h>

#define ll long long
#define ii pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi acos(-1.0)
#define oo 1000000007
#define loo 0x7fffffffffffffff

#define prime 1000000007

#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, ans = 0; cin >> n;
    vl a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        if(i){
            if(a[i] < a[i-1]) ans+=a[i-1]-a[i], a[i] = a[i-1];
        }
    }
    cout << ans << "\n";
    
    return 0;
}