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
   int A,B,m;
   cin >> A>>B>>m;
   vector<int>a(A),b(B);
   rep(i,A) cin >> a[i];
   rep(i,B) cin >> b[i];
   int ma = 220000;
   rep(i,m){
       int x,y,c;
       cin >> x>>y>>c;
       x--,y--;
       ma = min (ma,a[x]+b[y]-c);
   }
   int mia = 110000,mib= 110000;
   rep(i,A) mia = min(mia,a[i]);
   rep(i,B) mib = min (mib,b[i]);
   cout << min(ma,mia+mib) <<endl;
}