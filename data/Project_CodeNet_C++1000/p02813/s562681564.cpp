#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N;
    cin >> N;
    vector<int> P(N), Q(N), A(N);
    rep(i,N) cin >> P.at(i);
    rep(i,N) cin >> Q.at(i);
    rep(i,N) A.at(i) = i + 1;
    int cnt = 0;
    int cntP = 0;
    int cntQ = 0;
    do {
        if (P == A) cntP = cnt;
        if (Q == A) cntQ = cnt;
        ++cnt;
    } while (next_permutation(A.begin(), A.end()));
    cout << abs(cntP - cntQ) << endl;
}

