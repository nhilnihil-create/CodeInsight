#include <bits/stdc++.h>
using namespace std;

#define    int                      long long int
#define    ld                       long double
#define    f(i,j,n)                 for(int i = j; i <= n; i++)
#define    r(i,n,j)                 for(int i = n; i >= j; i--)
#define    mod                      1000000007
#define    speed                    ios_base::sync_with_stdio(false);
#define    upp                      cin.tie(NULL),cout.tie(NULL);
#define    pb                       push_back
#define    mp                       make_pair
#define    T                        int ttt; cin >> ttt; while(ttt--)
#define    ff                       first
#define    ss                       second
#define    all(container)            container.begin() , container.end()
#define    sz(container)            (int)container.size()
#define    pii                      pair <int , int>
#define    sp(x)                    setprecision(x)
#define    bp(x)                    __builtin_popcount(x)
#define    endl                     "\n"

int power(int x, int y, int p)  
{  
    int res = 1;    
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0)  
    {     
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res; 
}

int32_t main()
{
    speed upp
    int n,k,c,x=0;
    cin>>n>>k>>c;
    c++;
    string s;
    cin>>s;
    vector<int>a,b;
    for(int i=0;i<n;)
    {
        if(x>=k)
            break;
        if(s[i]=='x')
            i++;
        else
        {
            a.pb(i);
            x++;
            i+=c;
        }
    }
    x=0;
    for(int i=n-1;i>=0;)
    {
        if(x>=k)
            break;
        if(s[i]=='x')
            i--;
        else
        {
            b.pb(i);
            x++;
            i-=c;
        }
    }
    x=0;
    vector<int>ans;
    for(int i=0;i<k;i++)
        if(a[i]==b[k-1-i])
        {
             x++;
            ans.pb(a[i]);
        }
    f(i,0,x-1)
        cout<<ans[i]+1<<endl;
}