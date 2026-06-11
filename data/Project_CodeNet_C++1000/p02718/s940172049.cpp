#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define REP(i,m,n) for(ll i=(ll)(m); i<(ll)(n); ++i)
#define F first
#define S second
const double PI=acos(-1);
//fixed<<setprecision(11)<<

int main(){
  int n, m, sum = 0;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n){
    cin >> a[i];
    sum += a[i];
  }

  int b = (sum+4*m-0.1)/(4*m);
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());

  if(a[m-1] < b) cout << "No" << endl;
  else cout << "Yes" << endl;
return 0;
}