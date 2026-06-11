#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string t;
    cin>>t;
    int ans;
    int n=s.size(),m=t.size();
    ans=m;
    int countt=0;
    for(int i=0;i<n-m+1;i++)
    {   countt=0;
        string temp=s.substr(i,m);

        for(int j=0;j<m;j++)
        {
            if(temp[j]!=t[j])
                countt++;
        }
        //cout<<countt<<endl;
        ans=min(ans,countt);
    }
    cout<<ans;
}
