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

const int maxx = 1e6+5;

int main(){
	fast();
	int t=1;
	//cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> cn(maxx,0);
		int x;
		for(int i=0;i<n;i++){
			cin>>x;
			cn[x]++;
		}
		int c=0;
		vector<int> vis(maxx,0);
		for(int i=1;i<=1000000;i++){
			if(cn[i]==0 || vis[i]){
				continue;
			}
			if(cn[i]==1 && !vis[i]){
				c++;
			}
			for(int j=i;j<=1000000;j+=i){
				vis[j] = 1;
			}
		}	
		cout<<c<<endl;
	}
	
	return 0;
}
