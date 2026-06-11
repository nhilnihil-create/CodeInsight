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

ll n,m,cur = 1,i;
set<ll> s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>n>>m;
    ll p = 2*m + 1,piv = m + 1;
    for (i = 1;i <= piv/2;i++) cout<<i<<" "<<piv - i + 1<<"\n",m--;
    piv++;
    for (i = piv;m > 0;i++) cout<<i<<" "<<p - i + piv<<"\n",m--;
}

