#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef pair<string,string> Pstring;
typedef pair<double,double> Pdouble;


#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define Precision13 cout << fixed << setprecision(13)
const double PI=3.14159265358979323846;
const int MAX = 510000;
const int MOD = 1000000007;
const int INF = 1<<29;
using Graph = vector<vector<int>>;

int main() {
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  REP(i,n) cin >> a.at(i);

  ll s1=0;
  ll s2=0;
  for(int i=0; i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(a[i]>a[j]){
        s1++;
      }else if(a[i]<a[j]){
        s2++;
      }
    }
  }

  ll ans;
  ans = k*(k+1)/2%MOD*s1%MOD+(k-1)*(k)/2%MOD*s2%MOD;
  cout << ans%MOD << endl;

}



  
