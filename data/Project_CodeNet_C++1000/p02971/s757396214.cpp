#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N; cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    rep(i, N){
        int a; cin >> a;
        A[i] = a; B[i] = a;
    }
    sort(B.begin(), B.end());
    rep(i, N){
        if(A[i]==B[N-1]) cout << B[N-2] << endl;
        else cout << B[N-1] << endl;
    }
    return 0;
}
