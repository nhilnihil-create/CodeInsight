// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    ll sum = 0;
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    
    B[0] = sum;
    for(int i = 1; i < N; i += 2) B[0] -= 2 * A[i];
    
    for(int i = 1; i < N; i++){
        B[i] = 2 * A[i - 1] - B[i - 1];
    }

    rep(i, N) cout << B[i] << ' ';
    cout << endl;

}