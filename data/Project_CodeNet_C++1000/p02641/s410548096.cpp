#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    int ar[1000]={};

    cin>>a>>b;
   
    for(int i=0; i< b; i++)
    {
        cin>>c;
        ar[c] = 1;
    }
    int i =0;
    while(1)
    {
        if(ar[a-i] == 0)
        {
            cout<<a-i;
            return 0;
        }
        if(ar[a+i] == 0)
        {
            cout<<a+i;
            return 0;
        }
        i++;
    }
    return 0;
}
