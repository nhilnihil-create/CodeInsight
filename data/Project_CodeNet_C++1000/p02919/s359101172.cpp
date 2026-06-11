#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int man = 2e5+10;
#define IOS ios::sync_with_stdio(0)
template<typename T>T gcd(T a, T b) {return b==0?a:gcd(b, a%b);}
template<typename T>T exgcd(T a,T b,T &g,T &x,T &y){if(!b){g = a,x = 1,y = 0;}else {exgcd(b,a%b,g,y,x);y -= x*(a/b);}}
#ifndef ONLINE_JUDGE
#define debug(fmt, ...) {printf("debug ");printf(fmt,##__VA_ARGS__);puts("");}
#else
#define debug(fmt, ...)
#endif
typedef long long ll;
const ll mod = 1e9+7;
int lef[man][2],rig[man][2];
int pos[man];
int x[man];
int n;
int te[man*4];

void pushup(int rt){
    te[rt] = max(te[rt<<1] , te[rt<<1|1]);
}

void build(int l,int r,int rt){
    if(l==r){
        te[rt] = x[l]; 
        return;
    }
    int m = l+r>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);
}

int query(int l,int r,int L,int R,int rt){
    if(L<=l&&R>=r){
        return te[rt];
    }
    int ans = -1;
    int m = l+r>>1;
    if(L<=m)ans = max(ans,query(l,m,L,R,rt<<1));
    if(R>m)ans = max(ans,query(m+1,r,L,R,rt<<1|1));
    return ans;
    //pushup(rt);
}

void solve1(int id){
    int l = 1,r = id;
    int ans = 0;
    while(l<=r){
        int mid = l+r>>1;
        if(query(1,n,mid,id,1)>x[id]){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    lef[id][0] = ans;
    if(ans==0){
        lef[id][1] = 0;
        return;
    }
    l = 1,r = ans-1;
    int tp = ans-1;
    ans = 0;
    while(l<=r){
        int mid = l+r>>1;
        if(query(1,n,mid,tp,1)>x[id]){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    } 
    lef[id][1] = ans;
}

void solve2(int id){
    int l = id,r = n;
    int ans = n+1;
    while(l<=r){
        int mid = l+r>>1;
        if(query(1,n,id,mid,1)>x[id]){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    rig[id][0] = ans;
    if(ans==n+1){
        rig[id][1] = ans;
        return;
    }
    l = ans + 1,r = n;
    int tp = ans + 1;
    ans = n+1;
    while(l<=r){
        int mid = l+r>>1;
        if(query(1,n,tp,mid,1)>x[id]){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    rig[id][1] = ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",x+i);
        pos[x[i]] = i;
    }
    build(1,n,1);
    for(int i = 1;i <= n;i++){
        solve1(i);
        solve2(i);
    }
    // for(int i = 1;i <= n;i++){
    //     printf("%d: %d %d %d %d\n",i,lef[i][0],lef[i][1],rig[i][0],rig[i][1]);
    // }
    ll ans = 0;
    for(int i = 1;i <= n;i++){
        int lpos1 = lef[pos[i]][0];
        int lpos2 = lef[pos[i]][1];
        int rpos1 = rig[pos[i]][0];
        int rpos2 = rig[pos[i]][1];
       // printf("%d %d %d %d\n",lpos1,lpos2,rpos1,rpos2);
        if(lpos1)ans += 1ll*(lpos1 - lpos2)*(rpos1 - pos[i])*i;
       // printf("%lld\n",ans);
        if(rpos1<=n)ans += 1ll*(pos[i]-lpos1)*(rpos2-rpos1)*i;
       // printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
    return 0;
}