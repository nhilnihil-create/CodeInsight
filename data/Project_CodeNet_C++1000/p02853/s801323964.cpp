#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int num,sum=0;
  vector<int> m ={300000,200000,100000};
  for(int i =0; i < 2; i++){
   cin >> num;
   if(num < 4)
     sum += m.at(num-1);    
  }
  
  if(sum == 600000)
    cout << 1000000;
  
  else
    cout << sum;
  
  
}
