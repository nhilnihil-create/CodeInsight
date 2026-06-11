#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N;
    string S, T;
    cin >> N >> S >> T;
    rep(i, N){
        cout << S[i] << T[i];
    }
    cout << "\n";
    return 0;
}
