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
const long INF = 1e18;
void read(){freopen("input.txt" , "r" , stdin );freopen("output.txt", "w" , stdout );}
void solve(){
	long n, res = 1;
	cin >> n;
	long ar[n];
	for(auto &i: ar) cin >> i;
	sort(ar, ar + n);
	for (int i = 0; i < n; ++i){
		if( ar[i] == 0){ cout << 0; return; }
		if( res > INF / ar[i] ){ cout << -1; return;}
		res *= ar[i];
	}
	cout << res;
} 
int32_t main(){
ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
        cout << fixed << setprecision(9);
        long T = 1;
        //cin >> T;
        while( T-- ){
            solve();
            cout<<'\n';
        }
cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
} 													
