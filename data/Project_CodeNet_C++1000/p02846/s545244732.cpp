#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii  = pair<int,int>;
#define rep(i,n) for(auto i=0; i<(n); i++)
#define rep2(i,x,n) for(auto i=x; i<(n); i++)
#define MOD 1000000007
#define INF 1e+9
#define MAX_V 10

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const double PI = 3.141593;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}    //最大公約数
ll lcm(ll a,ll b) {return a * b / gcd(a, b);}   //最小公倍数
ll combination(ll n, ll r) {
  if ( r * 2 > n ) r = n - r;
  ll dividend = 1;
  ll divisor  = 1;
  for ( ll i = 1; i <= r; ++i ) {
    dividend *= (n-i+1);
    divisor  *= i;
  }
  return dividend / divisor;
}



int main() {

    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

    ll P,Q,S,T;

    P = (a1 - b1) * t1;
    Q = (a2 - b2) * t2;
    if(P>0){
        P *= -1;
        Q *= -1;
    }

    if (P+Q<0)
        cout << 0 << endl;
    else if (P+Q==0)
        cout << "infinity" << endl;
    
    else{
        S = -P/(P+Q);
        T = (-P) % (P + Q);
        if(T!=0)
            cout<<S * 2 + 1<<endl;
        else
        {
            cout << S * 2 << endl;
        }
    }
}