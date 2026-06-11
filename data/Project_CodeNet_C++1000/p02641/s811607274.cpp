#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define all(s) s.begin(),s.end()
#define pb push_back
#define uno unordered_map
#define pi 3.1415926536
#define dig(a) fixed<<setprecision(a)
#define foreach(var,i) for(auto i = var.begin();i!=var.end();i++)
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
ll power(ll a, ll n) {ll res = 1; while (n) {if (n % 2) {res *= a;} n >>= 1; a *= a;} return res;}
ll powerm(ll a, ll n, ll m) {ll res = 1; while (n) {if (n % 2) {res = (res * a) % m;} n >>= 1; a = (a * a) % m;} return res;}
const int M=1e9+7;
ll mod(ll x){
      return ((x%M + M)%M);
}
ll add(ll a, ll b){
      return mod(mod(a)+mod(b));
}
ll mul(ll a, ll b){
      return mod(mod(a)*mod(b));
}

int main(){
	fast();
	int t=1;
	//cin>>t;
	while(t--){
		int x,n;
		cin>>x>>n;
		vector<int> a(n);
		for(int &x:a){
			cin>>x;
		}
		sort(all(a));
		auto it = find(all(a),x);
		if(it==a.end()){
			cout<<x<<endl;
			continue;
		}
		int ind = it-a.begin();
		int k=1;
		int f=0;
		for(int j=ind;j-k>=0;k++){
			if(a[j-k]!=x-k){
				//cout<<x-k<<endl;
				f=x-k;
				break;
			}
			else{
				if(a[j+k]!=x+k){
					//cout<<x+k<,endl;
					f=x+k;
					break;
				}
			}
		}
		if(!f) cout<<a[0]-1<<endl;
		else cout<<f<<endl;
	}
	
	return 0;
}
