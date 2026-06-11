#include<iostream>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  double a = 0;
  double ans = 0;
  for(int i = 1;i <= n;i++){
    if(i % 2 == 1){
      a++;
    }
  }
  ans = a / n;
  cout << ans <<endl;
}