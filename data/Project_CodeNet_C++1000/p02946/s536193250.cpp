#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,x;
    cin>>k>>x;
    int m = x-k+1;
    if(k==1)
    {
        cout<<x<<endl;
    }
    else
    {

        for(int i=1;i<=2*k-1;i++)
        {
            cout<<m<<" ";
             m++;

        }

    }
    return 0;




}
