#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l,r,d,i,j,k=0;
    cin>>l>>r>>d;
    for(i=l;i<=r;i++)
    {
        if(i%d==0)
        {
            k++;
        }
    }
    cout<<k<<endl;
    
     
}
