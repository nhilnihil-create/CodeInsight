#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,s=0,k;
    
    cin>>n>>k;
    long long a[n];
    if(n<=k)
      cout<<"0";
    else
     {for(int i=0;i<n;i++) 
         cin>>a[i];
      
    sort(a,a+n,greater<int>());
    
      for(int i=k;i<n;i++)
         s+=a[i];
    
      cout<<s;
        
    }
  return 0;
}
     
   


