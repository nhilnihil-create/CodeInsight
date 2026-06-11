#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
using PL = pair<ll , ll> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int main(){
    string s ;
    cin >> s ;
    vector<int> a (2019) ;
    reverse(s.begin(), s.end()) ;
    int n = s.size() ;
    int ans = 0 ;
    int tot = 0 ;
    int x = 1 ;
    rep(i, n){
        a[tot]++ ;
        tot += (s[i] - '0') * x ;
        tot %= 2019 ;
        ans += a[tot] ;
        x *= 10 ;
        x %= 2019 ;
    }
    cout << ans << endl ;
}

