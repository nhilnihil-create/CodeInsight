#include <bits/stdc++.h>
 
#define int long long
#define endl '\n'
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i, l, r) for(int i=(int)(l);i<=(int)(r);i++)
#define repi(i, l, r) for(int i=(int)(l);i>=(int)(r);i--)
const int inf = 1e18;
 
using namespace std;
 
 
void solve() {
    int n;
    cin>>n;
    pair<int,int>p[n];
 
    rep(i,1,n){
        int x,y;
        cin>>x>>y;
        p[i].first = x;
        p[i].second = y;
    }
 
    int cnt = 0;
    bool flag = false;
    rep(i,1,n){
        if(p[i].first == p[i].second )
            cnt++;
        else
            cnt = 0;
        if(cnt >= 3){
            flag = true;
            break;
        }
    }
    if(flag)
        cout << "Yes\n";
    else
        cout << "No\n";
}
 
 
int32_t main() {
    fastIO
    int t = 1;
//    cin >> t;
    rep(i, 1, t) {
        solve();
    }
}