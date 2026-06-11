#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
// #define LOCAL
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int u=1,v=(n-1)/2;u<v&&m;++u,--v){
        cout<<u<<" "<<v<<"\n";
        m--;
    }
    for(int u=(n-1)/2+1,v=u+(n-1)/2;u<v&&m;++u,--v){
        cout<<u<<" "<<v<<"\n";
        m--;
    }
}
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    solve();
}