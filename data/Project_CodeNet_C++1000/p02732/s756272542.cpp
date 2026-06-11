#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//const ll INF = 1LL << 60;
//const int INF = 1001001001;

ll choose2(ll n){
    return n*(n-1)/2;
}

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i,n) cin >> a[i];
    REP(i,n) a[i]--;
    vector<int> cnt(n);
    REP(i,n) cnt[a[i]]++;
    ll tot=0;
    REP(i,n) tot+=choose2(cnt[i]);
    REP(i,n){
        ll ans=tot;
        ans-=choose2(cnt[a[i]]);
        cnt[a[i]]--;
        ans+=choose2(cnt[a[i]]);
        cout << ans << endl;
        cnt[a[i]]++;
    }

    return 0;
}