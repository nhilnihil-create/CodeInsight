#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "tst"
using namespace std;
const ll N = 5e3 + 9;
const ll inf = 1e9 + 7;
typedef pair<ll,ll> LL;

ll a,b,n;
ll cal(ll x){
    return floor((ld) (a*x)/b) - a*floor((ld) x/b);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>a>>b>>n;
    ll res = min(b - 1,n);
    cout<<cal(res);
}

