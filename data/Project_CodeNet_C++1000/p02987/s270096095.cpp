#include<bits/stdc++.h>
using namespace std;

#define lli long long int

int main()
{
 string s;
 cin>>s;
lli n=1,c=0;

for (int i=1;i<s.length();i++)
{
    c=0;
    for(int j=0;j<i;j++)
    {
        if (s[i]==s[j])
            break;
        else
            c++;
    }
    if(i==c)
        n++;
}

if(n==2)
    cout<<"Yes";
else
    cout<<"No";

    return 0;
}

