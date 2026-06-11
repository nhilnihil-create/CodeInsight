#include <iostream>
using namespace std;
#define min(a,b) ((a)<(b) ? (a) : (b))
int digit(int a){
  if(a==0) return 0;
  else return digit(a/10)+1;
}
int main(){
  int n,result=0;
  cin >> n;
  for(int i=1;i<=n;i++){
    if(digit(i)%2==1) result++;
  }
  cout << result << endl;
  return 0;
}