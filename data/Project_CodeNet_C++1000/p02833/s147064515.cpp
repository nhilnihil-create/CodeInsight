#include <bits/stdc++.h>
#define Int int64_t
#define pb push_back
using namespace std;

Int find(Int n) 
{ 
    Int count = 0; 
    for (Int i = 5; n / i >= 1; i *= 5) 
        count += n / i; 
  
    return count; 
} 
int main()
{
  Int N;cin>>N;
  if(N&1){
      cout<<0<<"\n";
      return 0;
  }
  cout<<find(N/2)<<"\n";
  
  
   
   
}