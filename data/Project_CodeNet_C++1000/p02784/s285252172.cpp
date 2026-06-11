#include<bits/stdc++.h>>
using namespace std;
int main()
{
    int h,n,k,sum=0;
    cin>>h>>n;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        sum=sum+k;
    }
    if(sum>=h)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}

