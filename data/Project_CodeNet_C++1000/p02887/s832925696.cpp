
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,d=0,e,f,g,h,i,j,k,l,m,n,x,y,z;
    cin>>a;
    char ch,dh;
    cin>>ch;

    for(i=1;i<a;i++)
    {

    cin>>dh;
    if(dh!=ch)
    {
        d++;
        ch=dh;
    }

    }
    cout<<d+1<<endl;







}
