#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,n,i,k;
    cin>>n;
    string str;
    cin>>str;
    for(i=0;i<str.length();i++)
    {
        k=str[i]-'A'+n;
        if(k>25)
        {
            r=k%26;
            cout<<char('A'+r);
        }
        else
        {
            cout<<char('A'+k);
        }
    }


 return 0;
}
