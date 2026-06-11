#include<bits/stdc++.h>
using namespace std;
string n;
int main()
{
    int i,c=0;
    cin>>n;
    for(i=0;i<n.length();i++)
    {
        if(n[i]=='7')
        {
            cout<<"Yes\n";
            c=1;
            break;
        }
    }
    if(c==0)
    {
        cout<<"No\n";
    }

return 0;
}

