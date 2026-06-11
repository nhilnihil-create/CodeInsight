#include <bits/stdc++.h>
using namespace std;
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;
int aray[200005];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, K; cin >> N >> K;
    ll v = 0, bes = 0; int cnt = 0;
    rep(i, N) {
        cin >> aray[i]; aray[i]++;
        v += aray[i];
        bes = max(bes, v);
        cnt++;
        if(cnt == K) {
            v -= aray[i-K+1];
            cnt--;
        }
    }
    cout << bes/2;
    if(bes%2) cout << ".5";
    cout << endl;
}