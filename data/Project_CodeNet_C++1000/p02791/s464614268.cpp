#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,i,c=1;
    cin>>n;
    int s[n];
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }

    for(i=0;i<n-1;i++)
    {

        if(s[i]>s[i+1])
        {
           // cout<<s[i]<<endl;
            c++;
        }
        else
        {
            s[i+1]=s[i];
        }
    }
    cout<<c<<endl;


    return 0;
}