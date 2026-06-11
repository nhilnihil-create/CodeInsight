#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long int k;
    cin>>k;
    long long int ans=0,f=0,nn=0,i;
    for(i=1;i<=7777777;i++)
    {
        //ans++;
         nn=(nn*10+7)%k;

         if(nn==0)
         {

             f=1;
             break;
         }

    }
    if(f==0)
        cout<<"-1\n";
    else
        cout<<i<<endl;
}
