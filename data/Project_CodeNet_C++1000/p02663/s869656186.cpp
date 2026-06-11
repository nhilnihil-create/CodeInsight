#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "test"
using namespace std;
const ll N = 100 + 9;
const ll inf = 1e9 + 7;
typedef pair<ll,ll> LL;

ll h1,h2,m1,m2,p1,p2,k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>h1>>m1>>h2>>m2>>k;
    p1 = h1*60 + m1;
    p2 = h2*60 + m2;
    cout<<max(0ll,p2 - p1 - k);
}
