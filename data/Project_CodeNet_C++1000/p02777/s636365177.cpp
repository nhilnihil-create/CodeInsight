#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    string S, T;
    cin >> S >> T;
    int A, B;
    cin >> A >> B;
    string U;
    cin >> U;
    if(S==U) cout << A-1 << " " << B << endl;
    else cout << A << " " << B-1 << endl;
    return 0;
}
