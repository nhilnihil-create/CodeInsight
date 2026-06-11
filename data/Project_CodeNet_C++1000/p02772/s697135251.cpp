#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define xrep(i,a,b) for(int i=int(a);i<int(b);++i)
using ll = long long;


int main() {
    int N;
    cin >> N;
    vector<int> A;
    rep(i, N) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    int evencnt = 0;
    vector<int> evenVec;
    rep(i, N) {
        if(A[i]%2==0) {
            ++evencnt;
            evenVec.push_back(A[i]);
        }
    }
    int cnt = 0;

    for(auto e: evenVec) {
        if(e%3==0 || e%5==0) ++cnt;
    }

    if(cnt==evenVec.size()) {
        cout << "APPROVED" << endl;
    }
    else {
        cout << "DENIED" << endl;
    }

    return 0;
}