// finish date: 2019/6/26

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, pair<int, int>> plii;
const int bigmod = 1000000007;
const int INF = 1000000007;
const long long INFll = 100000000000000000;


int main() {
    int N;
    cin >> N;
    vi A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int medA, medB;
    if (N % 2) {
        medA = A[N / 2];
        medB = B[N / 2];
        cout << int(medB - medA + 1) << endl;
    } else {
        medA = A[N / 2 - 1] + A[N / 2];
        medB = B[N / 2 - 1] + B[N / 2];
        cout << int(medB - medA + 1) << endl;

    }

}
