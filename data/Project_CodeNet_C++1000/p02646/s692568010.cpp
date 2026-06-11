#include <iostream>
using namespace std;
int main() {
  long long a,v,b,w,t;
  cin >> a >> v;
  cin >> b >> w;
  cin >> t;
  
  if (a>b){
    if (v*t>=a-b+w*t) cout << "YES";
    else cout << "NO";
  }else if (a<b){
    if (v*t>=b-a+w*t) cout << "YES";
    else cout << "NO";
  }
}
