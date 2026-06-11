#include <bits/stdc++.h>
using namespace std;
 
int main() {
     cout << fixed << setprecision(6);
           int n,k;
           cin >>n>>k;
   vector<long double> vec(n+1);
  vec[0]=0;
  vector<long double> vecvec(n+1,0);
  
    for (int i = 1; i <n+1; i++) {
        cin>> vec.at(i);
      vecvec[i]=(vec[i]+1)/2;

    }
  
 long double a=0;
  for(int i=0;i<=k;i++){
  a+=vecvec[i];
  
  }
if(n==k)cout<<a<<endl;

  else{
 long double c=0;

  for(int i=2;i<=n-k+1;i++){
    a=a-vecvec[i-1]+vecvec[i+k-1];
    c=max(c,a);
    
   
  }
    
    
  
 
  
cout <<c<<endl;
    }
}
