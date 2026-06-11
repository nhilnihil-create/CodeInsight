#include <bits/stdc++.h>
 
using namespace std;
 
 
int main()
{
    
    int n,k;
    cin>>n>>k;
    int d[k];
     int i,a;
     set<int >s;
     int j;
     for(i=0;i<k;++i)
       {
           cin>>d[i];
           for(j=0;j<d[i];++j)
             {
                 cin>>a;
                 s.insert(a);
             }
       }
       
      cout<<n-s.size(); 
   
       
       
    
     
     return 0;   
    
}