#include <iostream>
using namespace std;
int m(int x){
  if(x==1)return 300000;
  if(x==2)return 200000;
  if(x==3)return 100000;
  else return 0;
}
int main(){
  int a, b;
  cin >> a >> b;
  int sum = 0;
  sum+=m(a)+m(b);
  if(a==1&&b==1)sum+=400000;
  cout << sum << endl;
  return 0;
}
