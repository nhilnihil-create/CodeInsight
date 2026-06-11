#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const ll INF = 1e18 + 10;

int N;
bool app[2000200];

int main() {
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    sort(ALL(A));
    rep(i,N-1) if (A[i] == A[i+1]) app[A[i]] =true;
    rep(i,N) {
        for (int j = 2*A[i]; j <= A[N-1]; j += A[i]) { app[j] = true; }
    }
    int count = 0;
    rep(i,N) {
        if ( !app[A[i]] ) count++;
    }
    cout << count << endl;
}