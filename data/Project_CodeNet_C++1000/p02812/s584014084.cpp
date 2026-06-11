#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define rep(p,a,b) for(ll p=a ; p<b ; p++)
#define F first
#define S second
using namespace std;


int main()
{
    ll t,i,j,k,ans,n,x;

    //cin>>t;
    t=1;
    while(t--)
    {
        string s1="ABC",s;
        cin>>n>>s;
        s = s1+"#"+s;
        n = (ll)s.length();

        //cout<<s<<"\n";

        vector<ll> pi(n);
        ans=0;
        rep(p,1,n)
        {
            j = pi[p-1];
            //cout<<j<<"1\n";
            while(j>0 && s[j]!=s[p]){j = pi[j-1];}
            if(s[j]==s[p])j++;
            pi[p] = j;

            //cout<<pi[p]<<" ";
            if(pi[p]==3)ans++;
        }

        cout<<ans;
    }
    return 0;
}

