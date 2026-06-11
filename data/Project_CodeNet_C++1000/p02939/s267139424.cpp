#include <bits/stdc++.h>

#define int long long
#define ci(m)     for(int i=0;i<m;i++)
#define cj(m)     for(int j=0;j<m;j++)
#define ck(m)     for(int k=0;k<m;k++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;

int32_t main() {
    nitin;
    string s;
    cin>>s;
    int n=s.length();
    vector<int>v;
    int temp=1;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
            temp++;
        else
        {
            v.push_back(temp);
            temp=1;
        }
    }
    v.push_back(temp);
    int ans=0;
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i]==0)
            continue;
        int val=v[i];
        if(val%3==1)
        {
            ans+=((val/3)*2+1);
        }
        else if(val%3==0)
        {
            ans+=(val/3)*2;
        }
        else{
            v[i+1]--;
            val++;
            ans+=(val/3)*2;
        }
    }
    int val=v[v.size()-1];
    if(val%3==1)
    {
        ans+=((val/3)*2+1);
    }
    else if(val%3==0)
    {
        ans+=(val/3)*2;
    }
    else{
        ans+=(val/3)*2+1;
    }
    cout<<ans<<endl;
    return 0;
}