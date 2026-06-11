#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int sum = 0;
  int x;
  cin>>x;
  if(x<4)
    sum += (4-x)*100000;
  
  cin>>x;
  if(x<4)
    sum += (4-x)*100000;
  
  if(sum==600000)
    sum += 400000;
  
  cout << sum << endl;
    
}