#include<iostream>
#include<vector>
#include<string>
 
using namespace std;
 
int main(void){
	
  int n;
  int flag = 0;
  cin >> n;
  for(int i = 0; i < 3; i++){
    if(n%10 == 7)flag++;
    n /= 10;
  }
  
  if(flag != 0)cout << "Yes";
  else cout << "No";
  
  return 0;
}