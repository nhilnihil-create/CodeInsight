#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)
using namespace std;
using p=pair<int,int>;

int main() {
  int x,y,z;
  cin >> x >> y >> z;
  if(x==y&&x!=z){
    cout << "Yes" << endl;
  }
  else if(z==y&&x!=z){
    cout << "Yes" << endl;
  }
  else if(x==z&&x!=y){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;

}