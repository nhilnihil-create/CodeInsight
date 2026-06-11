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
	string s;
	cin >> s;
	long ans = 0;
	for (int i = 0; i < s.size(); ++i){
		ans += s[i] - '0';
	}
	if( ans % 9 ) cout << "No";
	else cout << "Yes";
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
