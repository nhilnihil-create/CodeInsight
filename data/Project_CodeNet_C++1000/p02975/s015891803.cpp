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
    int n;
    cin>>n;
    map<int,int>m;
    ci(n)
    {
        int a;
        cin>>a;m[a]++;
    }
    if(n%3!=0)
    {
        if(m.size()==1 && m.count(0))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        return 0;
    }
    bool flag=true;
    if(m.size()>3)
        cout<<"No"<<endl;
    else if(m.size()==3)
    {
        int a=0;
        for(auto c:m)
        {
            a^=c.first;
            if(c.second!=(n/3))
                flag=false;
        }
        if(a!=0)
            flag=false;
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
    else if(m.size()==2)
    {
        vector<int>v;
        v.reserve(m.size());
for(auto c:m)
            v.push_back(c.first);
        if(v[0]==0 || v[1]==0)
            ;
        else
            flag=false;
        if(m[v[0]]%(n/3)!=0)
            flag=false;
        if(m[v[1]]%(n/3)!=0)
            flag=false;
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
    else
    {
        if(m.count(0))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}