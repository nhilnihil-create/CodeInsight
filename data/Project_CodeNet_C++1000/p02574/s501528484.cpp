#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n"
#define all(s) s.begin(),s.end()
#define pb push_back
#define uno unordered_map
#define pi 3.1415926536
#define dig(a) fixed<<setprecision(a)
#define test(zz) int zz; cin>>zz; while(zz--)
#define foreach(var,i) for(auto i = var.begin();i!=var.end();i++)
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
ll power(ll a, ll n) {ll res = 1; while (n) {if (n % 2) {res *= a;} n >>= 1; a *= a;} return res;}
ll powerm(ll a, ll n, ll m) {ll res = 1; while (n) {if (n % 2) {res = (res * a) % m;} n >>= 1; a = (a * a) % m;} return res;}
using namespace std;

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
const int N = 1000005;

int main(){
	fast();
	//test(t){}
	
	int n;
	cin>>n;
	vector<int> a(n),fact(N);
	for(int i=0;i<n;i++){
		cin>>a[i];
		fact[a[i]]++;
	}
	
	bool f = true;
	for(int i=2;i<N;i++){
		int c=0;
		for(int j = i;j<N;j+=i){
			c+=fact[j];
		}
		if(c>1){
			f = false;
			break;
		}
	}
	if(f){
		cout<<"pairwise coprime"<<endl;
		return 0;
	}
	int g = 0;
	for(int i=0;i<n;i++){
		g = __gcd(g,a[i]);
	}
	if(g==1){
		cout<<"setwise coprime"<<endl;
		return 0;
	}
	cout<<"not coprime"<<endl;
	
	return 0;
}
