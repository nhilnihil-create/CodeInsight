#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t,n,i,j,k;
    string s;
    cin>>n;
    cin>>s;
    ll c=0;
    for(i=1;i<n;i++)
    {
        if(s[i-1]!=s[i])
        {
            c++;
        }
    }
    cout<<c+1<<endl;
    return 0;
}
