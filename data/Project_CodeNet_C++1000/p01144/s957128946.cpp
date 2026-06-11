#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cassert>
#include <complex>
#define repi(i,x,n) for(int i = x; i < n; i++)
#define rep(i,n) repi(i,0,n)
#define int long long
using namespace std;
const int INF = 1<<30;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    int ans;
    pair<int,int> d[10000];
    while(1){
        ans=0;
        cin>>n>>m;
        if(n==0 && m==0) break;
        rep(i,n){
            int a,b;
            cin>>a>>b;
            d[i]=make_pair(b,a);
        }
        sort(d,d+n);
        for(int i=n-1;i>=0;i--){
            if(d[i].second <= m){
                m-=d[i].second;
                d[i].second=0;
            }else{
                d[i].second-=m;
                break;
            }
        }
        rep(i,n){
            ans+=d[i].first*d[i].second;
        }
        cout<<ans<<endl;
    }
                
    return 0;
}



