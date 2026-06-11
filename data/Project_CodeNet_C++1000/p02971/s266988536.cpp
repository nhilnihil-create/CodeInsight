#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
int n;
  cin>>n;
  vector<int> vec(n);
  for(int i=0;i<n;i++)cin>>vec[i];
  int a_max=max(vec[0],vec[1]),a_second=min(vec[0],vec[1]);
  for(int i=2;i<n;i++){
  if(vec[i] >= a_max){
  a_second=a_max;
    a_max=vec[i];
    
  
  }
  else if(vec[i] >= a_second)a_second=vec[i];
    else continue;
  
  }
    for(int i=1;i<n+1;i++){
    if(vec[i-1] == a_max)cout << a_second <<endl;
      else cout << a_max <<endl;
      
    }
  
  
}