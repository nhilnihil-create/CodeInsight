#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N;
    int mi = 1001001001;
    cin >> N;
    vector<int> W(N), s(N+1, 0);
    rep(i, N){
        cin >> W[i];
        s[i+1] = s[i]+W[i];
    }
    rep(i, N) mi = min(abs((s[N]-s[i])-s[i]), mi);
    cout << mi << endl;
    return 0;
}
