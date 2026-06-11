#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }

typedef pair<int, int> P;
ll modnum = 1e9+7;


int main() {
    int n,k,c; cin >> n >> k >> c;
    string s; cin >> s;
    vector<int> adv(n, 0);
    vector<int> back(n, 0);
    int rem = -1;
    int now = 1;
    rep(i, n) {
        if(s[i] == 'o' && rem < 0) {
            adv[i] = now;
            rem = c;
            now++;
        }
        rem--;
    }

    rem = -1;
    now -= 1;

    if(now > k) return 0;

    for(int i=n-1; i >= 0; i--) {
        if(s[i] == 'o' && rem < 0) {
            back[i] = now;
            rem = c;
            now--;
        }
        rem--;
    }

    rep(i, n) {
        if(adv[i] > 0 && adv[i] == back[i]) cout << i + 1 << endl;
    }

    return 0;
}