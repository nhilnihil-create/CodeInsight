#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int i=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int i=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }


int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    for(int i=0; i<K; i++){
        vector<int> B(N+1);
        for(int j=0; j<N; j++){
            B[max(0, j-A[j])]++;
            B[min(N, j+A[j]+1)]--;
        }
        for(int j=1; j<N; j++) B[j] += B[j-1];
        for(int j=0; j<N; j++) A[j] = B[j];
        bool ok = true;
        for(auto x : A)
            if(x != N){
                ok = false;
                break;
            }
        if(ok) break;
    }
    REP(i, N){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}