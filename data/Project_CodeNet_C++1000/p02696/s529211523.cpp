#include <bits/stdc++.h>
using namespace std;
#define int long long int
signed main() 
{
          int A,B,N;
          cin>>A>>B>>N;
          if(N>=B)
          {
                    int ans=(A*(B-1))/B;
                    cout<<ans<<"\n";
          }
          else
          {
                   int ans=((A*N)/B);
                    
                    cout<<ans<<"\n";      
          }

}
