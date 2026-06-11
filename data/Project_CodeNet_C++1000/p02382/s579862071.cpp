#include <cstdio>
#include <utility>
#include <typeinfo>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <tuple>
#define REP(i,n) for(int i=0;i<n;i++)
typedef long long int ll;
using namespace std;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;

int main()
{

    ll n;
    double x[100]={};
    double y[100]={};
    
    cin>>n;
    REP(i,n){cin>>x[i];}
    REP(i,n){cin>>y[i];}
    
    for(int i=1;i<4;i++)
    {
        double ans(0);
        REP(j,n)
        {
            ans+= pow(max(x[j]-y[j],-x[j]+y[j]),i);
        }
        ans = pow(ans,1/(double)i);
        printf("%f\n",ans);
    }
    
    ll p(0);
    REP(i,n)
    {
        if(p<max(x[i]-y[i],-x[i]+y[i]))
        {
            p=max(x[i]-y[i],-x[i]+y[i]);
        }
    }
  
    cout<<p<<endl;
                  
    
    return 0;
}