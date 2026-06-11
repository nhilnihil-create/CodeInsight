#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int a[100010];
ll mn[100010],mx[100010];

int main(){
    int n;
    cin>>n;
    rep(i,n+1)cin>>a[i];
    mn[n]=mx[n]=a[n];
    for(int i=n; i>0; --i){
        mn[i-1]=a[i-1]+(mn[i]+1)/2;
        mx[i-1]=a[i-1]+mx[i];
    }
    if(mn[0]!=1){cout<<-1<<endl; return 0;}
    ll ans=0,now=1;
    rep(i,n+1){
        ans+=now;
        now-=a[i];
        now=min(now*2,mx[i+1]);
    }
    cout<<ans<<endl;
}