#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define REPD(i,n) FOR(i,n-1,0)
#define PB push_back
#define mod 1000000007


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a[n];
    float sum=0;
    REP(i,n)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sum=sum/(4*m);
    int c=0;
    REP(i,n)
    {
        if(a[i]>=sum)
        ++c;
    }
    if(c>=m)
    cout<<"Yes";
    else
    cout<<"No";
    
    
    
    return 0;   
}