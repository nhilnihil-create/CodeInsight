    #include <bits/stdc++.h>
    #include<math.h>
    #define rep(i,n) for (int i = 0; i < (n) ; ++i)
    using namespace std;
    using ll = long long ;
    using P = pair<int , int> ;
    #define PI 3.14159265358979323846264338327950
    #define INF 1e18 
     
    int main(){
        int n, m ,k ;
        cin >> n >> m >> k ;
        vector<int> a (n) ;
        vector<ll> b (m) ;
        rep(i, n) cin >> a[i] ;
        rep(i, m) cin >> b[i] ;
        ll sum = 0 ;
        rep(i, n){
            sum += a[i] ;
        }
        rep(i, m - 1) {
            b[i+1] += b[i] ;
        }

        int ans = 0 ;
        int f = n ;
        ll o = k - sum ;

        if(o >= 0) {
            int pp = lower_bound(b.begin(), b.end(), o) - b.begin() ;
            if(b[pp] == o){
                 pp++ ;
            }
            ans= max(ans, pp + f) ;
        }
        for(int i = n - 1 ; i >= 0 ; i--){
            f-- ;
            sum -= a[i] ;
            ll t = k - sum ; 
            if(t <= 0){
                continue ;
            }
            else {
                int p = lower_bound(b.begin(), b.end(),t) - b.begin() ;
                if(b[p] == t){
                    p++ ;
                }
                ans= max(ans, p + f) ;
            }
        }
        cout << ans << endl ;
        return 0 ;
    }