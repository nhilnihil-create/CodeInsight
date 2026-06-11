#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 100010;
const LL mod = 1e9+7;
const LL bit = 100001;
int f[SIZEN] = {0};
int g[SIZEN] = {0};
LL pw[SIZEN];
deque<int> q;
int N,M;
char str[SIZEN];    
void Print(int x){
    if(x == 0)return;
    Print(x-g[x]);
    printf("%d ",g[x]);
}
struct Node{
    int lch,rch;
    LL hash;
}t[SIZEN * 30];
int root[SIZEN] = {0};
int node = 0;
void updata(int &rt,int prt,int l,int r,int x,int y){
    rt = ++node;
    t[rt] = t[prt];
    if(l == r){
        t[rt].hash = y;
        return;
    }
    int mid = (l+r)/2;
    if(x <= mid)updata(t[rt].lch,t[prt].lch,l,mid,x,y);
    else updata(t[rt].rch,t[prt].rch,mid+1,r,x,y);
    int lch = t[rt].lch,rch = t[rt].rch;
    t[rt].hash = (t[lch].hash * pw[r-mid] % mod + t[rch].hash) % mod;
}
bool get(int rt,int prt,int l,int r){
    if(l == r)return t[rt].hash <= t[prt].hash;
    int mid = (l+r)/2;
    int lch = t[rt].lch,rch = t[rt].rch;
    int plch = t[prt].lch,prch = t[prt].rch;
    if(t[lch].hash != t[plch].hash)return get(lch,plch,l,mid);
    else return get(rch,prch,mid+1,r);
}
int main(){
    pw[0] = 1;
    for(int i = 1;i <= 100000;i++)pw[i] = pw[i-1] * bit % mod;
    scanf("%d%d",&N,&M);
    scanf("%s",str);
    memset(f,0x3f,sizeof f);
    f[0] = 0;
    q.push_front(0);
    for(int i = 1;i <= N;i++){
        if(str[i] == '0' && !q.empty()){
            f[i] = f[q.front()] + 1;
            g[i] = i - q.front();
            updata(root[i],root[q.front()],1,N,f[i],g[i]);
        }
        while(!q.empty() && i+1 - q.front() > M)q.pop_front();
        while(!q.empty() && i+1 - q.back()  > M)q.pop_back();
        if(str[i] == '0'){
            while(!q.empty() && ( f[i] < f[q.front()] || (f[i]==f[q.front()]&&get(root[i],root[q.front()],1,N)) ) )q.pop_front();
            while(!q.empty() && ( f[i] < f[q.back()] || (f[i]==f[q.back()]&&get(root[i],root[q.back()],1,N)) ))q.pop_back();
            q.push_back(i);
        }
    }
    // printf("N = %d\n",N);
    // for(int i = 1;i <= N;i++){
    //     printf("f[%d]=%d,g[%d]=%d\n",i,f[i],i,g[i]);
    // }
    if(f[N] >= 0x3f3f3f3f)puts("-1");
    else Print(N);
    return 0;
}