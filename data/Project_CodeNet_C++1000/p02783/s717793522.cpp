#include <iostream>
#include <cmath>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int a,b;
  cin>>a>>b;
  float ans = (a+b-1)/b;
  cout<<ceil(ans)<<"\n";
  return 0;
}
  
