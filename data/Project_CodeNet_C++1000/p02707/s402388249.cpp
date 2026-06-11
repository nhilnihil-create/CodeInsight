#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int N; cin >> N;
    vector<int> A(N+10,0);
    rep(i,N-1) {
        int a; cin >> a;
        A[a]++;
    }
    for(int i=1; i<=N; i++) cout << A[i] << endl;
}