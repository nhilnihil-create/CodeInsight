#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int (i)=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1000000007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

// boolean でのガウスの消去法を行い、ランクを返す
template<size_t BITSIZE>
int gaussian_elimination(vector<bitset<BITSIZE>> &A){
    int H = A.size();
    int W = BITSIZE;
    int rank = 0;
    for(int c=0; c<W; c++){
        int pivot = -1;
        for(int r=rank; r<H; r++){
            if(A[r][c]){
                pivot = r;
                break;
            }
        }
        if(pivot==-1) continue;
        swap(A[pivot], A[rank]);
        for(int r=0; r<H; r++)
            if(r != rank && A[r][c]) A[r] ^= A[rank];
        rank++;
    }
    return rank;
}

bitset<60> reverse(bitset<60> x){
    bitset<60> y;
    for(int i=0; i<60; i++)
        y[i] = x[59-i];
    return y;
}

int main(){
    int N;
    cin >> N;
    vector<unsigned long long> A(N);
    REP(i, N) cin >> A[i];
    vector<bitset<60>> B(N);
    REP(i, N) B[i] = A[i];

    unsigned long long ans = 0;
    REP(i, 60){
        int cnt = 0;
        REP(j, N) if(A[j]&(1LL<<i)) cnt++;
        if(cnt%2){
            ans += (1LL<<i);
            REP(j, N) B[j][i] = 0;
        }
    }
    REP(i, N) B[i] = reverse(B[i]);
    gaussian_elimination(B);
    REP(i, N) B[i] = reverse(B[i]);

    unsigned long long x = 0;
    REP(i, N) x ^= B[i].to_ullong();
    ans += 2 * x;
    cout << ans << endl;
    return 0;
}