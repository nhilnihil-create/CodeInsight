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
void solve(){
    long n;
    cin >> n;
    string s[n + 1];
    map <string, long> mp, us;
    for (int i = 0; i < n; ++i){
        cin >> s[i];
        mp[ s[i] ] ++;
    }
    long mx = 0;
    for (int i = 0; i < n; ++i){
        mx = max(mx, mp[ s[i] ]);
    }
    vector <string > v;
    for (int i = 0; i < n; ++i){
        if( mp[ s[i] ] == mx && us[ s[i] ] == 0 )
        v.pb(s[i]), us[ s[i] ] ++;
    }
    sort( all(v) );
    for (int i = 0; i < v.size(); ++i){
        cout << v[i] << '\n';
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