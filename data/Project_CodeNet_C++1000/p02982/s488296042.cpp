#include <bits/stdc++.h>

using namespace std;

int main()
{
      int n,d,sum=0,count=0;
      double x;
      cin>>n>>d;
      int a[n][d];
      for(int i=0; i<n; i++){
          for(int j=0; j<d; j++)
              cin>>a[i][j];
      }
      for(int i=0; i<n; i++){
          for(int j=i+1; j<n; j++){
              for(int k=0; k<d; k++){
                  sum+=pow((a[i][k]-a[j][k]),2);
              }
              x=sqrt(sum);
              sum=0;
              if(abs(x-int(x))==0){
                  count++;
              }
          }
      }
      cout<<count<<endl;
}