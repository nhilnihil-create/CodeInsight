//                                 Alisher_2211
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        # include <bits/stdc++.h>
# define  long          long long
# define  all(vc)       vc.begin(),vc.end()
# define  allr(vc)      vc.rbegin(),vc.rend()
# define  pb            push_back
# define  fi            first 
# define  se            second
# define  pi            pair <long, long>    
# define  lcm(a, b)     (a * b) / __gcd(a, b)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        using namespace std;
void read(){freopen("input.txt" , "r" , stdin );freopen("output.txt", "w" , stdout );}
long f(long n){
    return n * (n - 1) / 2;
}
void solve(){
      long n;
      cin >> n;
      for (int i = 1; i <= n; ++i){
            if( i < 6 ){ cout << 0 << '\n'; continue; }
            //if( i != 7 ) continue;
            long ans = 0;
            for (int x = 1; x < sqrt(i); ++x){
                for (int y = 1; y < sqrt(i) ; ++y){
                    //if( y != 2 ) continue;
                    long q = (x * x) + (y * y) + (x * y);
                    long w = -( i - q);
                    long e = x + y;
                    long d = (e * e) - (4 * w);
                    long o1 = (-e + sqrt( d ) ) / 2;
                    long o2 = (-e - sqrt( d ) ) / 2;
                    if( o1 > 0 ){
                        if( q + (o1 * o1) + (e * o1) == i ) ans ++;
                        //cout << ans << ' ' << x << ' ' << y << ' ' << o1 << '\n';
                    }   
                    else if( o2 > 0 ){
                        if( q + (o2 * o2) + (e * o2) ==i ) ans ++;
                        //cout << ans << ' ' << x << ' ' << y << ' ' << o2 << '\n';
                    }
                    //return;
                }
            }
            cout << ans << '\n';
      }
}
int32_t main(){
ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
        long T = 1;
        //cin >> T;
        while( T-- ){
            solve();
            cout<<'\n';
        }
cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}