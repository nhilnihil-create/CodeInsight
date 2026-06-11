#include<iostream>
#include<iomanip>
using namespace std;
main()
{

             long long x, n,k=0;
                cin>>n;
               long long MAX=n+1;

                for(int i=0;i<n;i++)
                {
                     cin>> x;
                     if(x<MAX)
                     {
                                     k++;
                                     MAX=x;
                     }
                }
                cout<<k<<endl;

}
