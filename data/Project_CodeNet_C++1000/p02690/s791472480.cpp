#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int                 long long   
#define double              long double
#define endl                "\n"
#define pb                  push_back
#define PI                  3.1415926535897932384626433832795l
#define F                   first
#define S                   second
#define mp                  make_pair
#define f(i,n)              for(int i=0;i<n;i++)
#define fastio              ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v)              (v).begin(),(v).end()
#define rall(v)             (v).rbegin(),(v).rend()
#define gcd(a,b)            __gcd((a),(b))
#define fill(a,value)       memset(a,value,sizeof(a));
#define minn(v)             *min_element(v.begin(), v.end());
#define maxx(v)             *max_element(v.begin(), v.end());
#define print(x)            cout<<(x)<<endl;
#define sum(v)+x            accumulate(v.begin(), v.end(),x);
#define debug(x)            cout<<#x<<'='<<(x)<<endl;
typedef pair<int,int> pii;  
typedef vector<int> vi;

signed main() 
{
    fastio;
    cout << fixed << setprecision(12);
    int x;
    cin>>x;
    for(int i=-1000;i<=1000;i++)
    {
        for(int j=-1000;j<=1000;j++)
        {
            if((pow(i,5)-pow(j,5))==x)
            {
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
    
    

    
    
    
    
    
    return 0;
}