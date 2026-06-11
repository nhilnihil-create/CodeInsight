#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int i=0; i<n; i++)
#define REP2(i, a, b) for(int i=a; i<b; i++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1'000'000'007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

int main(){
    int N;
    string S;
    cin >> N >> S;

    vector<int> lr(2*N);
    REP(i, 2*N){
        int parity = i%2;
        int par = (S[i]=='W'?0:1);
        if((parity^par) == 0) lr[i] = 1;
        else lr[i] = 0;
    }
    long long ans = 1;
    long long l = 0;
    REP(i, 2*N){
        if(lr[i] == 0) l++;
        else{
            ans *= l;
            ans %= MOD;
            l--;
        }
    }
    if(l != 0) ans = 0;
    REP(i, N){
        ans *= (i+1);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
