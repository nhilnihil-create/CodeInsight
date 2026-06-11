#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Maxn=1e5+10;
const ll Mod=1e9+7;
vector <ll> G[Maxn];
queue <ll> Q;
ll cnt[Maxn],fa[Maxn];
bool vis[Maxn];
ll n,k;
inline ll read(){
    ll s = 0, w = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
inline void write(ll x){
    if (x < 0) x = ~x + 1, putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
ll bfs(ll S){
    ll ans=k%Mod;
    Q.push(S);
    ll temp=Q.front();
    Q.pop();    vis[temp]=true;
    for(auto i:G[temp]){
        fa[i]=temp;
        Q.push(i);
    }
    while(!Q.empty()){
        ll temp=Q.front();
        vis[temp]=1;
        Q.pop();
        ll now=(fa[temp]==S)?k-1-cnt[fa[temp]]:k-2-cnt[fa[temp]];
        if(now<=0)    return 0;
        ans=(ans*now)%Mod;
        cnt[fa[temp]]++;
        for(auto i:G[temp]){
            if(!vis[i]){
                fa[i]=temp;
                Q.push(i);
            }
        }
    }
    return ans%Mod;
}
int main() {
    n=read();k=read();
    for(ll i=1;i<=n-1;i++){
        ll a,b;
        a=read();   b=read();
        G[a].push_back(b);
        G[b].push_back(a);
    }
    write(bfs(1));
    return 0;
}
