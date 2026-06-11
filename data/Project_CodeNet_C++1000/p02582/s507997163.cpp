#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int c=0;
    int l=0;
    for(int i=0;i<3;i++)
    {
        if(str[i]=='R')
        l++;
        else
        {
            if(l>c)
            c=l;
            l=0;
        }
    }
     if(l>c)
     c=l;
            cout<<c<<endl;
            return 0;
}