#include <bits/stdc++.h>
#define INF 1023456789
#define sacnf scanf
#define scnf scanf
#define scnaf scanf
#define CRLF <<'\n';
#define ALL(v) v.begin,v.end()
#define SIZE(v) (int)v.size()
#define PRPAIR(x) x.first << x.second
#define DEBUG(x) do { std::cerr <<(x)<<'\n'; } while (0)
#define rep(i,a,b) for(int i=(a);i!=(int)b-((a)>(b));(a)>(b)?--i:++i)
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> pip;
typedef vector<int> vi;
typedef long long ll;
#define MAXN 1000005

int k,n,arr[MAXN];

inline int ceiling(int n,int k){
    if (n%k==0)
        return n/k;
    else
        return n/k+1;
}

bool bsta(int t){
    ll c=0;
    rep(i,0,n){
        c+=ceiling(arr[i],t)-1;
    }
    return c <= k;
}

int main(){
    scanf("%d%d",&n,&k);

    int l=1,r=0;
    rep(i,0,n)
        scanf("%d",&arr[i]),r=max(r,arr[i]);

    int ans=INF;
    while(l <r){
        int mid =(l+r)/2;
        if (bsta(mid)){
            ans = min(ans,mid);
            r=mid;
        }else
            l=mid+1;
    }
    if (ans == INF){
        ans=0;
        rep(i,0,n){
            ans =max(ans,arr[i]);
        }
    }
    cout << ans;

}
