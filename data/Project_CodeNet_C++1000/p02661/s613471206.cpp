#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
ll MOD = 1000000007;
ll INF =1<<30;


int main(){
   ll n;
   cin >> n;
   vector<ll>a(n),b(n);
   rep(i,n){
      cin >> a[i] >>b[i];
   }
   sort(a.begin(),a.end());
   sort(b.begin(),b.end());
   double mi,ma;
   int ans;
   if(n%2!=0){
      mi = a[(n+1)/2-1];
      ma = b[(n+1)/2-1];
      ans = (ma-mi)+1;
   }
   else{
      double mi = (double)(a[n/2-1]+a[n/2])/2;
      double ma = (double)(b[n/2-1]+b[n/2])/2;
      ans = (ma-mi)*2+1;
   }
   cout << ans <<endl;
}