#include<bits/stdc++.h>
#define Rushia_mywife ios::sync_with_stdio(0);cin.tie(0);
#define rep(i,head,n) for(int i=(head);i<n;i++)
#define int long long
#define F first
#define S second
#define pb push_back
#define p2(n) (1<<(n))
#define lg2(n) __lg(n)
using namespace std;
using pii = pair<long long,long long>;
using ld = long double;
mt19937 mt_rand(time(0));
const int mod = 1000000007;
const int hnum = 998244353;
const ld PI = acos(-1);
const int N = 1e6+10;

int n,d;
int vis[N];
int cnt,cur;
bool cant;

void solve(){
    cin >> n;
    cur = 7%n;
    cnt = 1;
    while(cur&&!vis[cur]){
        cnt++;
        vis[cur] = 1;
        cur = cur*10+7;
        cur %= n;
        if(vis[cur])
            cant = 1;
    }
    cout << (cant ? -1 : cnt) << '\n';
}

signed main(){
    Rushia_mywife
    solve();
}