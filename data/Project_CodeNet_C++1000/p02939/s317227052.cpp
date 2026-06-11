#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, ans;
string s;
int main()
{
    IO
    cin>>s;
    s+='*';
    n=s.size();
    int cnt=1, last=0;
    for(int i=1; i<n; i++)
    {
        if(s[i]==s[i-1])
            cnt++;
        else
        {
            if(last)
                last=0, cnt--, ans++;
            ans+=cnt/3*2;
            cnt%=3;
            if(cnt==2)
                ans++, last=1;
            if(cnt==1)
                ans++;
            cnt=1;
        }
    }
    cout<<ans;
}
