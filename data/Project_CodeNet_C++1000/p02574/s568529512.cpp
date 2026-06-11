#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> val(1000001,0);
  rep(i,0,n) cin >> a[i];
  rep(i,0,n) {
    int vali=a[i];
    for(int j=2; j*j<=vali;j++){
      if(vali%j==0){
        val[j]++;
        vali/=j;
      }
      while(vali%j==0){
        vali/=j;
      }
    }
    if(vali!=1) val[vali]++;
  }
//  cout << val[2] << endl;
  bool pair=true;
  rep(i,2,1000001){
    if(val[i]==n){
      cout << "not coprime" << endl;
      return 0;
    }
    if(val[i]>=2) pair=false;
  }
  if(pair){
      cout << "pairwise coprime" << endl;
      return 0;
  }
  cout << "setwise coprime" << endl;
  return 0;
}