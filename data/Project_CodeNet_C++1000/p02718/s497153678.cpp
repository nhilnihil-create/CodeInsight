#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

int main(){
  int n,m,wa =0;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,n){
   cin >> a[i]; 
    wa += a[i];
  }
  int hantei = (wa+(4*m)-1)/(4*m);
  int counts = 0;
  rep(i,n){
   if(a[i] >= hantei) counts++;
  }
  if(counts >= m) cout << "Yes" << endl;
  else cout << "No" << endl;
}