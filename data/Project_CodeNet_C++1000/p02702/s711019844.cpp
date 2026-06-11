#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
int main () {
    string S;
    cin >> S ;
    reverse(S.begin(),S.end());
    vector<int> a(2019);
    int tot = 0 ;
    int x = 1 ;
    int n = S.size();
    ll ans = 0; 
    rep(i,n){
        a[tot]++ ;
        tot += (S[i] - '0') * x ;
        tot %= 2019 ;
        ans += a[tot] ;
        x *= 10 ;
        x %= 2019 ;
    }
    cout << ans << endl ;
}