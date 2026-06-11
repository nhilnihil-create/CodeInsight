#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep1n(i,n) for(int i=1; i<=(n); ++i)
#define repxn(i,x,n) for(int i=x; i<=(n); ++i)
#define sort_u(x) sort((x).begin(),(x).end())
#define sort_d(x) sort((x).begin(),(x).end(), greater<int>())
#define pb push_back
#define INF 1001001001  // 浮動小数点型
#define INF_L 1001001001001001001  // 浮動小数点型
#define bit(n,m)(((n)>>(m))&1)  // nのmビット目が1
#define MOD 1000000007
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
#define yn2 {puts("YES");}else{puts("NO");}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}

ll choose(ll a){
    return (a*(a-1))/2;
}

int main() {
    int n; cin>>n;
    vector<int> a(n); rep(i, n) cin >> a[i];
    rep(i,n) a[i]--;
    vector<int> cnt(n);
    rep(i,n) cnt[a[i]]++;
    ll ans=0;
    rep(i,n){
        //if(cnt[i]<2) continue;
        ans += choose(cnt[i]);
    }
    rep(i,n){
        ll tot = ans;
        tot -= choose(cnt[a[i]]);
        tot += choose(cnt[a[i]]-1);
        cout << tot << endl;
        // cout << ans - choose(cnt[a[i]]) + choose(cnt[a[i]]-1) << endl;        
    }
    
}

/*
g++ c.cpp
./a.out
./problem.exe
oj d
oj t

debug:ctrl+shift+B problemin

*/
