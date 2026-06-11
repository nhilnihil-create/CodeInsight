#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const double INF = 1e9;

//input
ll n;
vector<ll>a;
bool all_plus,all_minus;

void input(){
    cin >> n;
    a.resize(n);
    rep(i,n)cin>>a[i];
}

void sign_check(){
    all_plus=true;
    all_minus=true;
    rep(i,n){
        if(a[i]==0)continue;
        if(a[i]>0)all_minus=false;
        else all_plus=false;
    }
}

void solve_all_plus(){
    sort(a.begin(),a.end());
    ll x = a[0];
    vector<P>ans;
    for(int i=1;i<n-1;i++){
        ll y = a[i];
        ans.push_back({x,y});
        x -= y;
    }
    ans.push_back({a[n-1],x});
    x = a[n-1]-x;
    cout << x << endl;
    rep(i,ans.size()){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return;
}

void slove_all_minus(){
    sort(a.rbegin(),a.rend());
    vector<P>ans;
    ll x = a[0];
    for(int i=1;i<n;i++){
        ll y = a[i];
        ans.push_back({x,y});
        x -= y;
    }
    cout << x << endl;
    rep(i,ans.size()){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return;
}

void solve(){
    sort(a.begin(),a.end());
    vector<P>ans;
    ll x = a[0];
    for(int i=n-2;i>0;i--){
        if(a[i]<0)break;
        ll y = a[i];
        ans.push_back({x,y});
        x -= y;
    }
    ans.push_back({a[n-1],x});
    x = a[n-1]-x;
    for(int i=1;i<n;i++){
        if(a[i]>=0)break;
        ll y = a[i];
        ans.push_back({x,y});
        x -= y;
    }
    cout << x << endl;
    rep(i,ans.size()){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}


int main(){
    input();
    sign_check();
    if(all_plus)solve_all_plus();
    else if(all_minus)slove_all_minus();
    else solve();
    return 0;
}

