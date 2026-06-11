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
   ll h,w;
   cin >> h >>w;
   ll ans;
   if(h==1||w==1) {
       cout <<1 <<endl;
       return 0;
   }
   if(h%2==1&&w%2==1) {
       ans = h*w/2+1;
       cout << ans <<endl;
   }
   else {
       ans = w*h/2;
       cout << ans <<endl;
   }
}