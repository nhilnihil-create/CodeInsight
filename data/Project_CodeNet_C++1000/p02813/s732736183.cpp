#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;

int main() {
    
    int N;
    cin >> N ;
    int P[N];
    int Q[N];

    rep(i,N){
        cin >> P[i];
    }

    rep(i,N){
        cin >> Q[i];
    }

    vector<int> one_case_p;
    for (int i = 0; i < N; i++) { // one_case = {0,1,2,3,...n-1} とする
        one_case_p.emplace_back(P[i]);
    }

    vector<int> one_case_q;
    for (int i = 0; i < N; i++) { // one_case = {0,1,2,3,...n-1} とする
        one_case_q.emplace_back(Q[i]);
    }


    int rep_p = 0;
    do {
        rep_p += 1;
    } while (next_permutation(one_case_p.begin(), one_case_p.end()));

    int rep_q = 0;
    do {
        rep_q += 1;
    } while (next_permutation(one_case_q.begin(), one_case_q.end()));

    int ans = abs(rep_p - rep_q);

    cout << ans << endl;

}