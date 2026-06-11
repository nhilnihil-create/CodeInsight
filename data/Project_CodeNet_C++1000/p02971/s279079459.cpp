#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);

    rep(i, N) {
        cin >> A[i];
        B[i] = A[i];
    }

    sort(all(B));
    reverse(all(B));

    rep(i, N) {
        if (A[i] == B[0]) cout << B[1] << endl;
        else cout << B[0] << endl;
    }
    return 0;
}