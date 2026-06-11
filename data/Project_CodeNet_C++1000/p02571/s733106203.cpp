#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();
    int ans = 0;
    for(int i=0;i<=n-m;i++)
    {
        int count =0;
        for(int j=0;j<m;j++)
        {
            if(s[i+j] == t[j])
                count++;
        }
        ans = max(ans,count);
    }
    cout<<m-ans<<endl;
}