#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pb push_back
#define N 200001
#define ll long long
#define int ll 
#define pi pair<int , int>
#define pip pair<pair ,int>
#define mp make_pair 
#define f first
#define s second
#define mod 998244353
ll Mod(ll x, ll y, int p) 
{ll res = 1; x = x % p;
while (y > 0) 
{if(y & 1) res = (res*x) % p; 
y = y>>1;x = (x*x) % p; 
}return res; 
}
int* getlps(string pattern){
 int len = pattern.length();
 int * lps = new int[len];
 lps[0] = 0;
 int i = 1 , j = 0;
 while(i < len){
  if(pattern[i] == pattern[j]){
	  lps[i] = j+1;
   i++;
   j++;
  }
  else{
		if(j != 0){
		 j = lps[j-1];
		}
		else{
		 lps[i] = 0;
		 i++;
		}
  }
 }
 return lps;
}
class Triplet{
 public:
 int x ;
 int y ;
 int gcd;
};
Triplet extendedEuclid(int a , int b){
 if(b == 0){Triplet ans; ans.gcd = a;ans.x = 1;ans.y = 0;return ans;}
 Triplet smallAns = extendedEuclid(b , a%b);
 Triplet ans;
 ans.gcd = smallAns.gcd;
 ans.x = smallAns.y;
 ans.y = smallAns.x - (a/b)*smallAns.y;
 return ans;
}
int mmInverse(int a , int m){
 Triplet ans = extendedEuclid(a , m);
 return (ans.x+m)%m;
}
int fact[N];
void calfac(int n ){
fact[0] = 1;
for(int i = 1 ; i <= n+2; i++){
 fact[i] = (((fact[i-1]%mod)*(i%mod))%mod + mod)%mod;
}
 }
int calc(int n , int r){
 if(r > n)return 0;
 if(r == n)return 1;
 int ans = 1;
 ans = ((ans%mod)*(fact[n])%mod + mod)%mod;
 ans = ((ans%mod)*(mmInverse(fact[n-r] , mod)%mod) + mod)%mod;
 ans = ((ans%mod)*(mmInverse(fact[r] , mod)%mod) + mod)%mod;
 return (ans+mod)%mod;
}
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n, upto;
cin>>n>>upto;
int arr[n];
for(int i = 0 ; i  < n;i++){
	cin>>arr[i];
	arr[i] = arr[i]/2;
}
int dp[n];
for(int i = 0 ; i <  n;i++){
 int val = arr[i];
 int cnt = 0;
 while(val%2 == 0){
  val=val/2;
  cnt++;
  if(val == 0)break;
 }
 dp[i] = cnt;
}
map<int , int> m;
int odd = 0;
for(int i = 0 ; i < n ;i++){
  if(dp[i] > 0){
   m[dp[i]]++;
  }
  else{
      odd++;
  }
}
if(odd == 0 && (int)m.size() == 1){
	int lcm = arr[0];
	for(int i = 1 ; i < n; i++){
	     lcm = lcm*arr[i]/(__gcd(lcm , arr[i]));
	}
  cout<<((upto/lcm) + 1)/2<<endl;
   return 0;
}
if(m.size()){
   cout<<0<<endl;
   return 0;
}
// only odd values , 
int lcm = arr[0];
	for(int i = 1 ; i < n; i++){
	     lcm = lcm*arr[i]/(__gcd(lcm , arr[i]));
	}
   cout<<((upto/lcm) + 1)/2<<endl;
   return 0;
	
}
