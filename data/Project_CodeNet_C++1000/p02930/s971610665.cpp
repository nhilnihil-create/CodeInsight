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
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int d=10; d>=0; d--){
                if( (i&(1<<d)) != (j&(1<<d)) ){
                    A[i][j] = d;
                    break;
                }
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            cout << A[i][j]+1 << " ";
        }
        cout << endl;
    }

    return 0;
}
