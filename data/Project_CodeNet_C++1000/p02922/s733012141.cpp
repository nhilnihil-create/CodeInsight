#include<iostream>
using namespace std;
int main(){
  int a,b,i;
  cin >> a >> b;
  int c=1;
  for(i=0;;i++){
    if(c>=b){
      cout << i << endl;
      return 0;
    }
    c+=a-1;
  }
  return 0;
}
