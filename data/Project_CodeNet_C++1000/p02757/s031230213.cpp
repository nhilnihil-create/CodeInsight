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
const int MAXN=2e5+10;
int n,p;
char s[MAXN];
int cnt[10010];
void solve()
{
    scanf("%d %d\n",&n,&p);
    scanf("%s",s);
    ll ans=0;
    if(p==2){
        for(int u=n-1;u>=0;u--){
            if((s[u]-'0')%2==0){
                ans+=u+1;
            }
        }
        cout<<ans;
        return;
    }
    if(p==5){
        for(int u=n-1;u>=0;u--){
            if(s[u]=='0'||s[u]=='5'){
                ans+=u+1;
            }
        }
        cout<<ans;
        return;
    }
    int m=0,b=1;
    cnt[0]++;
    for(int u=n-1;u>=0;u--){
        m=(m+(s[u]-'0')*b)%p;
        b=b*10%p;
        ans+=cnt[m];
        cnt[m]++;
    }
    cout<<ans;
}
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    solve();
}