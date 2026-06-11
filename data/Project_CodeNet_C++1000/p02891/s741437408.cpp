#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string s;
    cin>>s;
    int k;
    cin>>k;
    long int ans=0,l=0,r=0,n=s.length(),z=0;
    vector<long int> v;
    while(1)
    {
        if(r>=n)
        break;
        while(r<n&&s[l]==s[r])
        r++;
        v.push_back((r-l)/2);
        if(r==n&&v.size()>1)
        {
            while(s[l]==s[r%n])
            r++;
            if(r>n)
            z=(r-l)/2;
            break;
        }
        l=r;
    }
    if(v.size()==1)
    ans=(k*s.length())/2;
    else if(z)
    {
        ans+=v[0]+v[v.size()-1];
        for(int i=1;i<v.size()-1;i++)
        ans+=k*v[i];
        ans+=(k-1)*z;
    }
    else
    {
    	for(int i=0;i<v.size();i++)
    	ans+=k*v[i];
	}
    cout<<ans<<endl;
}
