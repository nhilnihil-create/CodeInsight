#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int H, A;
    cin >> H >> A;
    if(H%A==0) cout << H/A << endl;
    else cout << H/A+1 << endl;
    return 0;
}
