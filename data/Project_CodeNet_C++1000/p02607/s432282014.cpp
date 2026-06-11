#include <iostream>
using namespace std;
 int main()
   {
     int N,s=0;
     cin>>N;
     int a[N];
     for(int i=1;i<=N;i++)
        {
          cin>>a[i];
          if(a[i]%2!=0&&i%2!=0)
            {
              s++;
            }
        }
    cout<<s<<endl ;
  
   }
