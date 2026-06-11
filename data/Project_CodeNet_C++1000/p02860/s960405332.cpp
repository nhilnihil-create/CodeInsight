#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

signed main(){
    int N;
    string S;
    cin >> N >> S;
    bool ok = true;
    if(N % 2 == 1) ok = false;
    else{
        REP(i, N / 2){
            if(S[i] != S[N / 2 + i]) ok = false;
        }
    }
    if(ok) PRINT("Yes");
    else PRINT("No");
    return 0;
}