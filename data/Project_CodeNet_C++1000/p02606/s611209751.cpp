#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l,r,d;
    cin>>l>>r>>d;
    int count=0;
    for(int i=l/d;i<=r;i++)
    {
       if(d*i>=l && d*i<=r)
            count++;
    }
    cout<<count<<endl;
}
