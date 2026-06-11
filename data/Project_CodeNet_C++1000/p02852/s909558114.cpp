#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int N, M;
string S;

string solve(){
    int index = N, next = 0;
    string ret;
    while(index > 0){
        next = max(0, index - M);
        while(S[next] == '1') next++;
        if(index == next) break;
        ret = to_string(index - next) + " " + ret;
        index = next;
    }
    if(index != 0) return "-1";
    ret.pop_back();
    return ret;
}

signed main(){
    cin >> N >> M >> S;
    PRINT(solve());
    return 0;
}