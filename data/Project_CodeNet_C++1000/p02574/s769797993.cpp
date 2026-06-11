#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// X以下の正数N個与えられたときに、全て素因数分解するためのプログラム
const int X = 1e+6 + 10;
int N;
vector<int> A,D;

// 計算量　前処理 O(X) ?
// D[x] = y のとき、正数xの最小の素因数がyである。(xが素数のときD[x]=x)
void sieve() {
    iota(D.begin(),D.end(),0);
    for ( int i = 2; i * i < X; ++i){
        if ( D[i] < i ) continue;
        for ( int j = i * i; j < X; j += i){
            if ( D[j] == j ) D[j] = i;
        }
    }
}
// 各素因数分解 O(logX)
// Yの素因数分解を行う
vector<int> factor( int Y ){
    vector<int> f;
    while ( Y > 1 ){
        f.push_back(D[Y]);
        Y /= D[Y];
    }
    return f;
}

// a と b の最大公約数を返す関数
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    cin >> N;
    A.resize(N); D.resize(X);
    REP(i,N) cin >> A[i];
    
    sieve();
    
    map<int,int> m;
    bool pairwise = true;
    REP(i,N){
        vector<int> f = factor(A[i]);
        set<int> s;
        for ( auto a: f) s.insert(a);
        for ( auto a: s){
            //cout << i << " " << a << endl;
            m[a] = m[a] + 1;
            if ( m[a] > 1 ) {
                pairwise = false;
                break;
            }
        }
    }
    
    bool setwise = true;
    int p = A[0];
    for ( int i = 1; i < N; ++i){
        p = GCD(p,A[i]);
    }
    if ( p != 1 ) setwise = false;
    
    if ( pairwise ) cout << "pairwise coprime" << endl;
    else if ( setwise ) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
    
    return 0;
}
