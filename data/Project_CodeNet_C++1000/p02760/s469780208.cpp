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
  vector<vector<int>> a(3, vector<int>(3));
  rep(i, 3){
    rep(j, 3)
    cin >> a[i][j];
  }
  int n;
  cin >> n;
  vector<int> b(n);
  rep(i, n) cin >> b[i];

  rep(k, n){
    rep(i, 3){
      rep(j, 3)
      if(a[i][j] == b[k]) a[i][j] = 0;
    }
  }

  if(a[0][0] == 0 && a[1][0] == 0 && a[2][0] == 0){
    cout << "Yes" << endl;
    return 0;
  }
  else if(a[0][1] == 0 && a[1][1] == 0 && a[2][1] == 0){
    cout << "Yes" << endl;
    return 0;
  }
  else if(a[0][2] == 0 && a[1][2] == 0 && a[2][2] == 0){
    cout << "Yes" << endl;
    return 0;
  }
  else if(a[0][0] == 0 && a[0][1] == 0 && a[0][2] == 0){
    cout << "Yes" << endl;
    return 0;
  }
  else if(a[1][0] == 0 && a[1][1] == 0 && a[1][2] == 0){
    cout << "Yes" << endl;
    return 0;
  }else if(a[2][0] == 0 && a[2][1] == 0 && a[2][2] == 0){
    cout << "Yes" << endl;
    return 0;
  }
  else if(a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0){
    cout << "Yes" << endl;
    return 0;
  }
  else if(a[2][0] == 0 && a[1][1] == 0 && a[0][2] == 0){
    cout << "Yes" << endl;
    return 0;
  }
  else cout << "No" << endl;
return 0;
}