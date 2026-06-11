
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cs=1;
    //scanf("%d",&cs);
    while(cs--)
    {
        int n,k,c;
        int i;
        string s;
        vector<int>l,r;
        cin>>n>>k>>c>>s;
        i=0;
        while(l.size()<k&&i<n)
        {
            if(s[i]=='o')
            {
                l.push_back(i);
                i+=(c+1);
            }else i++;
        }
        i=n-1;
        while(r.size()<k&&i>=0)
        {
            if(s[i]=='o')
            {
                r.push_back(i);
                i-=(c+1);
            }else i--;
        }
        reverse(r.begin(),r.end());
        int j;
        for(i=0,j=0;i<l.size()&&j<r.size();i++,j++)
        {
            if(l[i]==r[i])
            {
                cout<<l[i]+1<<endl;
            }
        }
    }
}
