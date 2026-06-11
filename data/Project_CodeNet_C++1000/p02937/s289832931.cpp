#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll occur[26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    string t;
    cin>>s;
    cin>>t;
    vector<ll>alpha[26];
    for(ll i=0;i<s.length();i++)
    {
        occur[s[i]-'a']=1;
        alpha[s[i]-'a'].push_back(i);
    }
    ll flag=1;
    for(ll i=0;i<t.length();i++)
    {
        if(occur[t[i]-'a']==0)
        {
            flag=0;
        }
    }
    if(flag==0)
    {
        cout<<"-1";
        return 0;
    }
    ll ans=-1;
    ll count=0;
    for(ll i=0;i<t.size();i++)
    {
        auto it=upper_bound((alpha[t[i]-'a']).begin(),(alpha[t[i]-'a']).end(),ans);
        if(it==(alpha[t[i]-'a']).end())
        {
            count++;
            ans=*(alpha[t[i]-'a'].begin());
        }
        else
        {
            ans=*it;
        }
    }
    cout<<ans+1+count*s.length();
	return 0;
}