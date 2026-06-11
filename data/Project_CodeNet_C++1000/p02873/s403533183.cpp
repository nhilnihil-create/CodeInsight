#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
//#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    string S; cin >> S;
    0 < 3 > 2 > 1 > 0 < 1 < 2 > 0 < 1 < 2 < 3 < 4 < 5 > 2 > 1 > 0 < 1;
    ll ans = 0, cntDai = 0, cntSho = 0;
    rep(i, S.size() - 1) {
        if(S[i] == '>' && S[i + 1] == '>') {
            cntSho++;
        }else if(S[i] == '<' && S[i + 1] == '<') {
            cntDai++;
        }else if(S[i] == '<' && S[i + 1] == '>') {
            cntDai++;
        }else if(S[i] == '>' && S[i + 1] == '<') {
            cntSho++;
            if(cntDai < cntSho) swap(cntDai, cntSho);
            ans += (cntDai + 1) * cntDai / 2;
            ans += (cntSho - 1) * cntSho / 2;
            //ans に加算
            cntSho = 0;
            cntDai = 0;
        }
    }
    if(S[S.size() - 1] == '>') ++cntSho;
    else ++cntDai;
    if(cntDai < cntSho) swap(cntDai, cntSho);
    ans += (cntDai + 1) * cntDai / 2;
    ans += (cntSho - 1) * cntSho / 2;

    cout << ans << endl;
}
