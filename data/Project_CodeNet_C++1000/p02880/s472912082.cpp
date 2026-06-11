#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    bool ans=false;
    cin>>n;
    for(i=1;i<=9;i++)
    {
        if(n%i==0&&n/i<=9)
        {
            ans=true;
            break;
        }
    }
    cout<<(ans?"Yes":"No")<<endl;
}
