//To all well wishers,I own this code
#include <bits/stdc++.h>
using namespace std;
#define int                     long long   
#define double                  long double
#define endl                    "\n"
#define pb                      push_back
#define PI                      3.1415926535897932384626433832795l
#define F                       first
#define S                       second
#define mp                      make_pair
#define f(i,n)                  for(int i=0;i<n;i++)
#define fastio                  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v)                  (v).begin(),(v).end()
#define rall(v)                 (v).rbegin(),(v).rend()
#define gcd(a,b)                __gcd((a),(b))
#define fill(a,value)           memset(a,value,sizeof(a));
#define minn(v)                 *min_element(v.begin(), v.end());
#define maxx(v)                 *max_element(v.begin(), v.end());
#define print(x)                cout<<(x)<<endl;
#define sum(v)+x                accumulate(v.begin(), v.end(),x);
#define debug(x)                cout<<#x<<'='<<(x)<<endl;
typedef pair<int,int>           pii;
typedef vector<int>             vi;

signed main() 
{
    fastio;
    cout << fixed << setprecision(12);
    string s,t;
    cin>>s>>t;
    map<char,vector<int>>m;
    int n=s.size();
    int freq[26]={0};
    for(int i=0;i<n;i++)
    {
        freq[s[i]-'a']=1;
        m[s[i]].pb(i);
    }
    bool flag=true;
    for(int i=0;i<(int)t.size();i++)
    {
        if(freq[t[i]-'a']==0)
        {
            flag=false;
        }
    }
    if(!flag)
    {
        print(-1)
    }
    else
    {
        int prev=-1;
        int ans=1;
        for(int i=0;i<(int)t.size();i++)
        {
            auto lower = lower_bound(m[t[i]].begin(), m[t[i]].end(), prev);
            if(lower==m[t[i]].end())
            {
                ans++;
                lower=m[t[i]].begin();
            }
            prev=*lower+1;
        }
        int x=(ans-1)*s.length();
        x+=prev;
        print(x)
        
    }
    
    
    return 0;
}


