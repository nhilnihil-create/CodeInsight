#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int (i)=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1000000007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }


int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    vector<int> B(N+1), C(N+1);
    REP(i, N) B[A[i]]++;
    REP(i, N+1) C[B[i]]++;
    vector<int> D(N+1);
    long long hoge = 0, fuga = 0;
    for(int i=1; i<=N; i++) hoge += C[i];
    for(int i=1; i<=N; i++){
        D[i] = hoge + fuga / i;
        hoge -= C[i];
        fuga += i*C[i];
    }
    //cerr << A << endl;
    //cerr << B << endl;
    //cerr << C << endl;
    //cerr << D << endl;
    vector<int> ans(N+1);
    for(int i=1; i<=N; i++){
        ans[D[i]] = i;
    }
    for(int i=N-1; i>=0; i--)
        ans[i] = max(ans[i], ans[i+1]);
    //cerr << ans << endl;
    for(int i=1; i<=N; i++)
        cout << ans[i] << endl;

    return 0;
}