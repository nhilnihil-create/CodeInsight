#include<iostream>
#include<cmath>
 
using namespace std;
 
int main(){
  int h,w,n;
  cin >> h;
  cin >> w;
  cin >> n;
  
  int a = max(h,w);
  int count = 0;
  
  while(1){
    n-=a;
    count++;
    if(n<=0){
      break;
    }
  }
  
  cout << count << endl;
  return 0;
}