#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,m,c=0;
    string s;
    cin>>n;
    cin>>s;
    for(int i=0;i<n-1;i++)
    {
        if(s[i+1]!=s[i])
            c++;
    }
    cout<<c+1<<endl;
}
