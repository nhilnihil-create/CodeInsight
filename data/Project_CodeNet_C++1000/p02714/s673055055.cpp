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

int main(void){
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    REP(i,n){
        if(s[i]=='R') a[i]=0;
        if(s[i]=='G') a[i]=1;
        if(s[i]=='B') a[i]=2;
    }
    vector<ll> cnt(3);
    REP(i,n) cnt[a[i]]++;
    ll ans=1;
    REP(i,3) ans*=cnt[i];
    REP(j,n)REP(i,j){
        int k=j+(j-i);
        if(k<n){
            if(a[i]==a[j]) continue;
            if(a[i]==a[k]) continue;
            if(a[k]==a[j]) continue;
            ans--;
        }
    }
    cout << ans;
    return 0;
}