#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int         long long   
#define double      long double
#define endl        "\n"
#define pb          push_back
#define PI          3.1415926535897932384626433832795l
#define F           first
#define S           second
#define mp          make_pair
#define f(i,n)      for(int i=0;i<n;i++)
#define fastio      ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v)      (v).begin(),(v).end()
#define rall(v)     (v).rbegin(),(v).rend()
#define gcd(a,b)    __gcd((a),(b))
#define fill(a,value) memset(a,value,sizeof(a));
#define minn(v)     *min_element(v.begin(), v.end());
#define maxx(v)     *max_element(v.begin(), v.end());
#define print(x)    cout<<(x)<<endl;
#define sum(v)+x    accumulate(v.begin(), v.end(),x);
#define debug(x)    cout<<#x<<'='<<(x)<<endl;
typedef pair<int,int> pii;  
typedef vector<int> vi;
signed main() 
{
    fastio;
    cout << fixed << setprecision(12);
    int n,k;
    cin>>n>>k;
    vi a(n);
    f(i,n)cin>>a[i];
    set<int> s;
    int i=0;
    vi p;
    p.pb(1);
    s.insert(1);
    vi cycle;
    vi noncycle;
    int store;
    while(true)
    {
        if(s.find(a[i])!=s.end())
        {
            store=a[i];
            break;
        }
        else
        {
            s.insert(a[i]);
            p.pb(a[i]);
            i=a[i]-1;
        }
    }
    bool flag=true;
    for(int i=0;i<(int)p.size();i++)
    {
        if(p[i]==store)flag=false;
        if(flag)noncycle.pb(p[i]);
        else cycle.pb(p[i]);
    }
    if(k<(int)noncycle.size())
    {
        print(noncycle[k]);
    }
    else
    {
        k-=(int)noncycle.size();
        print(cycle[(k%(int)cycle.size())])
    }
    
    
    
    
    
    
    
    return 0;
}