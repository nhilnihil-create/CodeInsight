#include<bits/stdc++.h>
#define ll long long
#define vl vector
#define pb push_back
using namespace std;
int main()
{
    ll a,b,i,j,n,k;
    string s;
    cin>>n>>s;
    ll flag=0;
    for(i=0;i<1000;i++)
    {
        string t;
        t=to_string(i);
        a=t.size();
        for(j=0;j<3-a;j++)
        {
            t="0"+t;
        }
        k=0;
        for(j=0;j<s.size();j++)
        {
            if(s[j]==t[k]) k++;
            if(k==3) break;
        }
        if(k==3) flag++;
    }
    cout<<flag;
}