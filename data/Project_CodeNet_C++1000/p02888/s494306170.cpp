#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,n,j,k,c=0;
    cin>>n;
    long long A[n];
    for(i=0;i<n;i++) cin>>A[i];
    sort(A,A+n);
    for(i=0;i<n;i++)
      {
        for(j=i+1;j<n;j++)
        {
          for(k=j+1;k<n;k++)
          {
                if(A[i]+A[j]>A[k])
                c++;
          }
        }

      }

    cout<<c<<endl;

return 0;
}
