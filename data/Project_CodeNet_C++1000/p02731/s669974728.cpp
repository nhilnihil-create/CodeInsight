#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int l;
  cin >> l;
  
  double s = (double)l/3;
  
  cout << fixed << setprecision(15) << s*s*s << endl;
  
  return 0;
}