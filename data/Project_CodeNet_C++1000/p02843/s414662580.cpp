#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i;
    bool a=false;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        if(i*100<=n&&i*105>=n)
        {
            a=true;
            break;
        }
    }
    cout<<(a?"1":"0")<<endl;
}
