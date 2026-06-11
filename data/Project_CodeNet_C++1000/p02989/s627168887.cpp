#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    rep(i, N) cin >> v[i];
    sort(v.begin(), v.end());
    if(v[N/2-1]==v[N/2]) cout << "0" << endl;
    else cout << v[N/2]-v[N/2-1] << endl;
    return 0;
}
