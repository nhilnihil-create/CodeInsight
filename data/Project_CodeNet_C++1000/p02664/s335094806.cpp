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

string s;
ll n,i;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>s; n = s.size();
    for (i = 0;i < n;i++){
        if (s[i] == '?') cout<<'D';
        else cout<<s[i];
    }
}
