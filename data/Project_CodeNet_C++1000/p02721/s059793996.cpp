#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int (i)=0; (i)<(n); (i)++)
#define REP2(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1000000007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

vector<int> calc(string &S, int N, int C){
    vector<int> ret(N+1);
    int cur = 0, last=-(1<<30);
    for(int i=0; i<N; i++){
        if(S[i] == 'x'){
            ret[i+1] = cur;
            continue;
        }
        if(i < last+C+1) ret[i+1] = cur;
        else{
            cur++;
            ret[i+1] = cur;
            last = i;
        }
    }
    return ret;
}

int main(){
    int N, K, C;
    string S;
    cin >> N >> K >> C >> S;
    string T = S;
    reverse(T.begin(), T.end());
    auto L = calc(S, N, C);
    auto R = calc(T, N, C);
    for(int i=0; i<N; i++){
        if(L[i]+R[N-1-i]<K) cout << i+1 << endl;
    }
    return 0;
}

