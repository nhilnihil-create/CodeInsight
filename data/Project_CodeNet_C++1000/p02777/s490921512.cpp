#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  string s,t;
  cin >> s >> t;
  int a,b;
  cin >> a >> b;
  string u;
  cin >> u;
  if(s==u){
    cout << a-1<<' '<<b << endl;
  }
  else{
    cout << a <<' '<< b-1 << endl;
  }
  
 
  return 0;

}