#include<bits/stdc++.h>
using namespace std;
  
 
int main(){
     int N;
     cin >> N;
  std::vector<int> v;
  int sum = 0;
  for(int i=0;i<N;i+=1){
       int x;
       cin >> x;
          v.push_back(x);
          sum+=x;
  }
  int b=999999;
  int right = 0;
  for(int i=(N-1);i>=0;i-=1){
          sum-=v[i];
          right+=v[i];
          int ans = abs(sum-right);
          if(ans<b){
               b = ans;
          }
  }
  cout << b;
  
  
     
}