#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    vector<int> A(n), B(p, 0);
    B[0]++;
    long long ans = 0;
    if (p==2 || p==5) {
        rep(i,n) {
            if ((s[i]-'0')%p==0) ans += i+1;
        }
    } else {
        int t = 1;
        rep(i,n) {
            A[i] = ((s[n-i-1]-'0') % p) * t % p;
            t = (t*10) % p; 
            if (i > 0) A[i] = (A[i] + A[i-1]) % p;
            ans += B[A[i]];
            B[A[i]]++;
        }    
    }
    cout << ans << endl;
    return 0;
}