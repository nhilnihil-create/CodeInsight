#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l,r,m;
    cin>>l>>r>>m;
    int cnt=0;
    for(int i=l;i<=r;i++)
    {
        if(i%m==0)cnt++;
    }

    cout<<cnt<<endl;
}
