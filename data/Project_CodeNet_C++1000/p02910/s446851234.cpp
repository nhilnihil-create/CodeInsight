#include<bits/stdc++.h> 
using namespace std;
int main()
{
    string str;
    cin>>str;
    int n= str.length(),i,x=0,y=0;
    for (i=0;i<n;i++)
    {
        if (i%2==0)
        {
            if (str[i]=='R'||str[i]=='U'||str[i]=='D')
                x++;
        }
        else 
        {
            if (str[i]=='L'||str[i]=='U'||str[i]=='D')
                y++;
        }
    }
    if (n%2==0)
    {
        if (x==n/2 && y==n/2)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    else
    {
        if (x==n/2+1 && y==n/2)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    
}