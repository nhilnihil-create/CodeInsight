#include <iostream>
using namespace std;
int main(){
  int a,b,result=0,tmp=1;
  cin >> a >> b;
  while(tmp<b){
    tmp--;
    tmp+=a;
    result++;
  }
  cout << result << endl;
  return 0;
}