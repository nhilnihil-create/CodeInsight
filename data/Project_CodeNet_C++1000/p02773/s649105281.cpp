#include <bits/stdc++.h>

using namespace std;

int c[200005];

string s[200005];

int main()
{
    string str;
    int n,a=0,b=1;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }

    sort(s,s+n);

    str=s[0];
    for(int i=1; i<n; i++)
    {
        if(s[i]!=str)
        {
            str=s[i];
            c[a]=b;
            a++;
            b=1;
        }
        else
        {
            b++;
        }
    }
    c[a]=b;
    sort(c,c+a+1);


    int y=c[a],k=1;

    if(y==1)
    {
        cout<<s[0]<<endl;
    }
    for(int i=1; i<n; i++)
    {
        if(s[i-1]==s[i])
        {
            k++;
        }
        else
        {
            k=1;
        }
        if(k==y)
        {
            cout<<s[i]<<endl;
        }
    }

    return 0;
}