#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i,j;
    long long r=0;
    for(i=1;i<=n;i++)
    {
        long long int s=0;
        for(j=1;;j++)
        {
            if(i*j<=n) s+=(i*j);
            else break;
        }
        //cout<<s<<endl;
        r += s;
    }
    cout<<r;
    return 0;
}