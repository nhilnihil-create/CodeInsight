/* BISMILLAHIR RAHMANIR RAHIM */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,cnt=0,c=1,t=1;
    string s;
    cin>>n;
    cin>>s;
    for(int i=0;i<n;)
    {
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')
        {
            cnt++;
            i+=3;
        }
        else i++;
    }
    cout<<cnt<<endl;
    return 0;
}

