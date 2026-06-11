#include <iostream>
using namespace std;
int main(){
  long long int a,b,c,d,e;
  cin >> a >> b >> c;
  d=c-a-b;
  if(d<=0) cout << "No" << endl;
  else{
     d=d*d;
     e=4*a*b;
     if(e<d) cout << "Yes" << endl;
     else cout << "No" << endl;
  }
  return 0;
}