#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,r,x=0;
    cin>>n;


    r=n%1000;
    if(r==0)
    {
        cout<<"0";
    }
    else
    {

        x=1000-r;
        cout<<x;
    }



    return 0;

}

