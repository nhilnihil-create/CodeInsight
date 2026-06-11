#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define RFOR(i,a,b) for(int i=(b-1); i>=(a); i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define pb push_back
using ll = long long;
using D = double;
using LD = long double;
using P = pair<int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n);
    rep(i,n) {
        a[i] = s[i] - '0';
        a[i]--;
    }

    vector<int> cnt(3);
    rep(i,n) cnt[a[i]]++;

    int type = -1;
    if(cnt[0] == n || cnt[1] == n || cnt[2] == n){
        cout << 0 << endl;
        return 0;
    }
    else if(cnt[0] == 0 ){
        type = 0;
        rep(i,n) a[i]--;
    }
    else if(cnt[1] == 0){
        type = 1;
        rep(i,n) a[i] /= 2;
    }
    else if(cnt[2] == 0){
        type = 2;
    }
    else{
        type = 3;
        rep(i,n) if(a[i] == 2) a[i] = 0;
    }

    int ans = 0;

    rep(i,n) if(((n-1) & i) == i) ans ^= a[i];

    if(type == 1) ans *= 2;
    cout << ans << endl;
}
