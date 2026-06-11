#include<iostream>
#include<vector>
using namespace std;

int main(void){
  
  int n,i;
  vector<int> fb(1000001);
  long long sum = 0;
  
  cin >> n;
  for(i=1;i<n+1;i++){
    fb.at(i) = i;
    if((i % 3 | i % 5) == 0) fb.at(i) = 0;
    else{
   if(i % 3 == 0) fb.at(i) = 0;
   if(i % 5 == 0) fb.at(i) = 0;
    }
    sum += fb.at(i);
  }
 
  cout << sum;
  return 0;
}