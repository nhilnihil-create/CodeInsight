//                                 Alisher_2211
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        # include <bits/stdc++.h>
# define  long          long long
# define  all(vc)       vc.begin(),vc.end()
# define  allr(vc)      vc.rbegin(),vc.rend()
# define  pb            push_back
# define  fi            first 
# define  se            second
# define  pi            pair <long, string>    
# define  lcm(a, b)     (a * b) / __gcd(a, b)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        using namespace std;
const long N = 100100;
void read(){freopen("input.txt" , "r" , stdin );freopen("output.txt", "w" , stdout );}
void solve(){
    string s;
    long n, m, x, a = 0, b = 0;
    cin >> n >> m;
    map <long, long> u, g;
    vector <pi> v;
    for (int i = 0; i < m; ++i){
        cin >> x >> s;
        v.pb({x, s});
        if( u[x] ) continue;
        if( s == "AC" ) u[x] = 1, a ++;
    }
    for (int i = 0; i < m; ++i){
        if( u[ v[i].fi ] == 0 ) continue;
        if( v[i].se == "AC" ) g[ v[i].fi ] = 1;
        if( g[ v[i].fi ] == 0 ) b ++;
    }
    cout << a << ' ' << b;
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