#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "test"
using namespace std;
const ll N = 5e3 + 9;
const ll inf = 1e9 + 7;
typedef pair<ll,ll> LL;

ll a,b,k,t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin>>k>>a>>b;
    for (ll i = a;i <= b;i++){
        if (i%k == 0){
            cout<<"OK"; return 0;
        }
    }
    cout<<"NG";
}

