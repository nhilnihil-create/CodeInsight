#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a;
    int ans=0;
    while(cin>>a)
    {
        a=(int)a-'0';
        ans+=a;
    }
    if(ans%9==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
