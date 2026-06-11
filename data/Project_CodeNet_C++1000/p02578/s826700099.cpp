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
const long N = 100100;
void read(){freopen("input.txt" , "r" , stdin );freopen("output.txt", "w" , stdout );}
long dp[N][2];
void solve(){
    long a;
    cin >> a;
    vector <long> v(a);
    for(auto &i: v) cin >> i;
    long mx = 0, ans = 0;
    for (int i = 0; i < a; ++i){    
        if( mx < v[i] ){
            mx = v[i];
            continue;
        }
        if( mx == v[i] ) continue;
        ans += mx - v[i];
    }
    cout << ans;
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