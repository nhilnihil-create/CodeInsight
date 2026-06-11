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
ll n,m,v,p,a[N],i;
ll ans,maxx,cnt;
bool lf(ll x,ll y){
    return x > y;
}
bool chk(ll mid){
    multiset<ll> s;
    vector<ll> res;
    ll cnt = 0,bigger = 0;
    for (i = 1;i <= n;i++){
        ll p = min(m,a[mid] + m - a[i]);
        if (p < 0) bigger++;
        s.insert(max(0ll,p));
    }
    while(s.size() > n - p + 1){
        res.push_back(m);
        s.erase(s.begin());
    }
    for (auto i : res) s.insert(i);
    while(!s.empty()){
        cnt += *s.begin(); s.erase(s.begin());
    }
    return (cnt >= m*v&&bigger < p);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>n>>m>>v>>p;
    for (i = 1;i <= n;i++){
        cin>>a[i];
    }
    sort(a + 1,a + n + 1,lf);
    ll l,mid,h;
    l = 1; h = n;
    while(l <= h){
        mid = (l + h)/2;
        if (chk(mid)) l = mid + 1;
        else h = mid - 1;
    }
    cout<<h;
}
