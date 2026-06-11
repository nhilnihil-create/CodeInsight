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
    string S;
    string T[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    cin >> S;
    REP(i, 7){
        if(S == T[i]){
            PRINT(7 - i);
            return 0;
        }
    }
    return 0;
}