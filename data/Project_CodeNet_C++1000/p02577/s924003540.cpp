#include <bits/stdc++.h>
using namespace std;


int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    int sum,ds,i;
       cin>>str;
    sum=0;
    for (i=0; str[i]!='\0'; i++)
    {
        sum+=str[i]-'0';
    }
    if (sum%9==0)
        cout<<"Yes"<<'\n';
    else
        cout<<"No"<<'\n';
    return 0;
}
