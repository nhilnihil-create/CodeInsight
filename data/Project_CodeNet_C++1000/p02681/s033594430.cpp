#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

int main(){
  string a,b;
  int counts = 0;
  cin >> a >> b;
  rep(i,a.size()){
   if(a.at(i) != b.at(i)) counts++;
  }
  if(counts != 0) cout << "No" << endl;
  else cout << "Yes" << endl;
}