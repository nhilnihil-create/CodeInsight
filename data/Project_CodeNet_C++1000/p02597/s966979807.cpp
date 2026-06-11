#include<bits/stdc++.h>
using namespace std;
#define ll long long
char str[200002];

int main()
{
    int n,i,j,cnt=0;
    cin>>n>>str;
    for(i=0,j=n-1;i<=j;)
    {
        if(str[i]=='R')i++;
        if(str[j]=='W')j--;
        if(i<=j && str[i]=='W' && str[j]=='R')
        {
            cnt++,i++,j--;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
