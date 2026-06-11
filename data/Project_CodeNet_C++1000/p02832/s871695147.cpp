#include <bits/stdc++.h>
using namespace std;
 
int main() {
    
           int n;
           cin >>n;

    vector<int> vec(n+1);
  vec[0]=0;
 
  int k=1;
  int cnt=n;
    for (int i = 1; i <=n; i++) {
        cin>> vec.at(i);
    }
  
 bool A=false;
  for(int i=1;i<=n;i++){
  if(vec[i]==k){
    A=true;
    k++;
   cnt--;
 }

  }
if(A)cout<<cnt<<endl;
  else cout <<"-1"<<endl;
  
}