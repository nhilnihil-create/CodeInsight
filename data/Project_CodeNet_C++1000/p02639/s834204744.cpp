#include <bits/stdc++.h>
using namespace std;
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
const int MAX = 1e5+5;
int main(){
	fast();
//	test(t){
//		
//	}
	vector<int> v(6,0);
	int x;
	for(int i=1;i<=5;i++){
		cin>>x;
		v[i] = x;
	}
	for(int i=1;i<=5;i++){
		if(v[i]==0){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
