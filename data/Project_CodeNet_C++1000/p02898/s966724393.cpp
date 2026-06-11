#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
//using namespace __gnu_pbds; 

#define rep(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define trace(x) cout << #x << ": " << x << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
#define fill(x,v) memset(x, v, sizeof(x))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

int main(){
  int n,k, a;
  cin >> n >> k;
  ll rpta =0 ;
  rep(i,0,n){
    cin >> a;
    if(a >= k) rpta++;
  }
  cout << rpta << endl;
} 