#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "tst"
using namespace std;
const ll N = 1e6 + 9;
const ll inf = 1e9 + 7;
typedef pair<ll,ll> LL;
queue<ll> q;
string s;
ll n,i,ans,cur = 0;
ll res[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>s; n = s.size(); s = " " + s;
    for (i = 1;i <= n;i++) if (s[i] == '<') q.push(i);
    q.push(n + 1);
    while(!q.empty()){
        ll t = q.front(); q.pop();
        for (i = cur; i < t;i++) res[i] = (t - i - 1);
        if (cur > 0) res[cur] = max(res[cur],res[cur - 1] + 1);
        cur = t;
    }
    for (i = 0;i <= n;i++) ans += res[i];
    cout<<ans;
}
