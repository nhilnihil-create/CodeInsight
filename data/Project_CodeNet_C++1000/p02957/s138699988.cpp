#include <bits/stdc++.h> 
#define ll long long int 
using namespace std; 
  
int main() 
{  
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL);   
    ll a,b; 
    cin>>a>>b;
if((abs(a+b))%2==1)  cout<<"IMPOSSIBLE"<<endl; 
else cout<<((a+b)/2)<<endl;
    return 0; 
} 
