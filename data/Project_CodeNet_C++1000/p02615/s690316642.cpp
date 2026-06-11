#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,x,n) for (int i = x; i < n; i++)
using ll = long long int;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A.at(i);
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    ll ans=0;
    rep(i,N) {
        if (i==0) continue;
        else if (i==1) ans += A.at(0);
        else ans += A.at(i/2);
    }
    cout << ans << endl;
    return 0;
}