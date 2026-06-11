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
 
int dig(int x)
{
    int ans=0;
    while(x>0)
    {
        ans++;
        x/=10;
    }
    return ans;
}
signed main() 
{
    fastio;
    cout << fixed << setprecision(12);
    string s;
    cin>>s;
    int n=s.size();
    vi a(n,0);
    int Lcur=1;
    int i=0;
    int Rcur;
    while(i<n)
    {
        if(s[i]!=s[i+1])
        {
            int j=i+1;
            Rcur=1;
            while(j<n)
            {
                if(s[j]!=s[j+1])
                {
                    if((Lcur+Rcur)%2==0)
                    {
                        a[i]=(Lcur+Rcur)/2;
                        a[i+1]=(Lcur+Rcur)/2;
                    }
                    else
                    {
                        if(Lcur>Rcur)
                        {
                            a[i]=(Lcur+Rcur)/2+1;
                            a[i+1]=(Lcur+Rcur)/2;
                            if(Lcur%2==0)
                            {
                            swap(a[i+1],a[i]);
                            
                            }
                        }
                        else
                        {
                            a[i]=(Lcur+Rcur)/2;
                            a[i+1]=(Lcur+Rcur)/2+1;
                            if(Rcur%2==0)
                            {
                            swap(a[i+1],a[i]);
                            
                            }
                        }
                        
                    }
                    break;
                    
                }
                else
                {
                    Rcur++;
                }
                j++;
            }
            i=j+1;
            Lcur=1;
            
        }
        else
        {
            Lcur++;
            i++;
        }
        
    }
    if((Lcur+Rcur)%2==0)
    {
        a[i]=(Lcur+Rcur)/2;
        a[i+1]=(Lcur+Rcur)/2;
    }
    else
    {
        if(Lcur>Rcur)
        {
            a[i]=(Lcur+Rcur)/2+1;
            a[i+1]=(Lcur+Rcur)/2;
        }
        else
        {
            a[i]=(Lcur+Rcur)/2;
            a[i+1]=(Lcur+Rcur)/2+1;
        }
        if(Lcur%2==0)
        {
            swap(a[i+1],a[i]);
            
        }
    }
    for(auto p:a)
    {
        cout<<p<<" ";
    }
    
    
    return 0;
}