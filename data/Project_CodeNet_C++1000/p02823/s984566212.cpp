#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "tst"
using namespace std;
const ll N = 2e5 + 9;
const ll inf = 1e6 + 7;
typedef pair<ll,ll> LL;

ll n,a,b,ans1,ans2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin>>n>>a>>b;
    if ((b - a)%2 == 0) cout<<(b - a)/2;
    else{
        ans1 = a + (b - a - 1)/2;
        ans2 = n - b + 1 + (b - a - 1)/2;
        cout<<min(ans1,ans2);
    }

}
