#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int i=0,j=0;
    int cnt=0;
    while(i<3 && j<3)
    {
        if(s[i]==t[j])
        cnt++;
        
        i++;
        j++;
    }
    cout<<cnt;
}