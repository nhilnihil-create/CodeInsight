#include <bits/stdc++.h>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
template<class T>bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;

//for(i=0; i<N; i++) cin >> a[i];


int main(void) {
  ll i, j, k;
  
  ll N;
  ll a[MAX*2];
  
  cin >> N;
  ll X=0;
  for(i=0; i<N; i++) {
    cin >> a[i];
    X^=a[i];
  }
  
  for(i=0; i<N; i++) pt((X^a[i]));
  
  
  
  
  
  
  
  
  
}
 
 


