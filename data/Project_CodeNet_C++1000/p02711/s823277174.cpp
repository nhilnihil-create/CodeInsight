#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,re,flag;
    while(cin>>n)
    {
        flag=0;
        while(n!=0)
        {
            re=n%10;
            if(re==7)
            {
                flag=1;
                break;
            }
            n=n/10;
        }
        if(flag==1)
            cout<<"Yes";
        else
            cout<<"No";
    }
}
