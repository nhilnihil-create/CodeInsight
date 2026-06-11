#include<iostream>
using namespace std;
int main(){
  int i=0,a,b,ans=1;
  cin >> a >> b;
  while(ans<b){
    ans=ans+a-1;
    i++;
  }
  cout << i << endl;
  return 0;
}