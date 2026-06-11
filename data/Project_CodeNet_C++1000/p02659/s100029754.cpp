    #include <bits/stdc++.h>
    #include<math.h>
    #include<algorithm> 
    #define rep(i,n) for (int i = 0; i < (n) ; ++i)
    using namespace std;
    using ll = long long ;
    using P = pair<int, int> ;
    #define PI 3.14159265358979323846264338327950
    #define INF 1e18
     
    int main() {
        ll a ;
        double b ; 
        cin >> a >> b ;
        ll c = (ll)(b * 100 + 0.5) ;
        ll ans = a * c / 100;
        cout << ans << endl ;
    } 