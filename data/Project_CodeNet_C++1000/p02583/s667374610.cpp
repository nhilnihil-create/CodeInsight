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
void solve(){
	long n;
	cin >> n;
	vector <long> v(n);
	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}
	long ans = 0;
	sort(all(v));
	for (int i = 0; i < n; ++i){
		for (int j = i + 1; j < n; ++j){
			for (int k = j + 1; k < n; ++k){
				if( v[i] != v[j] && v[j] != v[k] ){
					if( v[i] + v[j] > v[k] && 
						v[i] + v[k] > v[j] && 
						v[k] + v[j] > v[i] ){
						ans ++;
					}
				}
			}
		}
	}
	cout << ans;
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
