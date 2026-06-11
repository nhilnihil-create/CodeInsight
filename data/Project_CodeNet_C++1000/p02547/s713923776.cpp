#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int d1[N],d2[N],n;
int main()
{
    cin>>n;
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        cin>>d1[i]>>d2[i];
    }
    for(int i=1;i<=n-2;i++)
    {
        if(d1[i]==d2[i]&&d1[i+1]==d2[i+1]&&d1[i+2]==d2[i+2])
        {
             flag=1;
             break;
        }
    }
    if(flag==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
