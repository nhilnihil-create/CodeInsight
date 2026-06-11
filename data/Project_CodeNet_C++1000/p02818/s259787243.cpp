#include <bits/stdc++.h>
using namespace std;


int main() {
  int64_t A,B,K;
  cin>>A>>B>>K;
  
  if(K>=A+B) cout<<0<<" "<<0<<endl;
  else if(K<=A) cout<<A-K<<" "<<B<<endl;
  else cout<<0<<" "<<A+B-K<<endl;
    
  
  
 
}