#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define endl "\n"

constexpr long long INF = (long long)1e18;
constexpr long long MOD = 1'000'000'007; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}



signed main(){
	// cin.tie(nullptr);
	// ios::sync_with_stdio(false);
	// cout<<fixed<<setprecision(10);
	
	int k, q;
	vector<int> d;
	
	cin>>k>>q;
	
	d.resize(k);	


	for(int i = 0; i < k; i++){
		cin>>d[i];
	}
	
	for(int i = 0; i < q; i++){
		int n, x, m, ans = 0, sum = 0;
		
		cin>>n>>x>>m;
		
		sum = x;
		
		for(int i = 0; i < k; i++){
			if(d[i] % m == 0) {
				ans += (n - 1 - i + k - 1) / k;
			}
			sum += (d[i] % m) * ((n - 1 - i + k - 1) / k);
			// cout<<"i = "<<i<<" "<<(n - 1 - i + k - 1) / k<<endl;
		}
		
		
		ans += sum / m - x / m;
		
		// cout<<"ans = "<<ans<<endl;
		
		ans = n - 1 - ans;
		
		// cout<<"sum = "<<sum<<" "<<ans<<endl;
		
		cout<<ans<<endl;
	}
	
	return 0;
}