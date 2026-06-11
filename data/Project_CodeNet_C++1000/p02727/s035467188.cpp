#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
using namespace std;
const long long maxn=1e4+10;
const long long inf=1e15;
void in(long long &x){
    long long y=1;char c=getchar();x=0;
    while(c<'0'||c>'9'){if(c=='-')y=-1;c=getchar();}
    while(c<='9'&&c>='0'){ x=(x<<1)+(x<<3)+c-'0';c=getchar();}
    x*=y;
}
void o(long long x) {
    if (x < 0){
        putchar('-');
        x = -x;
    }
    if (x > 9)o(x / 10);
    putchar(x % 10 + '0');
}
long long read(){
    long long  res=0;
    long long  y=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')y=-1;c=getchar();}
    while(c<='9'&&c>='0'){res=(res<<1)+(res<<3)+c-'0';c=getchar();}
    return res*y;
}

long long X,Y,A,B,C;
vector<long long>vx,vy,vc,vv;
bool cmp(long long x,long long y){
    return x>y;
}
signed main(){
    in(A);in(B);in(X);in(Y);in(C);
    for(long long i=1;i<=X;i++){vx.push_back(read());}
    for(long long i=1;i<=Y;i++){vy.push_back(read());}
    for(long long i=1;i<=C;i++){vc.push_back(read());}
    sort(vx.begin(),vx.end(),cmp);
    sort(vy.begin(),vy.end(),cmp);
    sort(vc.begin(),vc.end(),cmp);
    long long pa=A-1,pb=B-1,pc=0,ans=0;
    for(long long i=0;i<=pa&&i<vx.size();i++){
        ans+=vx[i];
        vv.push_back(vx[i]);
    }
    if(pa>=vx.size()){
        for(long long i=0;i<A-vx.size();i++){
            ans+=vc[i];
            pc++;
        }
    }
    for(long long i=0;i<=pb&&i<vy.size();i++){
        ans+=vy[i];
        vv.push_back(vy[i]);
    }
    if(pb>=vy.size()){
        for(long long i=pc;i<B-vy.size()+pc;i++){
            ans+=vc[i];
            pc++;
        }
    }
    sort(vv.begin(),vv.end(),cmp);
    long long pvv=vv.size()-1;
    while(pc<vc.size()&&0<=pvv&&vv[pvv]<vc[pc]){
        ans-=vv[pvv];
        ans+=vc[pc];
        pvv--;
        pc++;
    }
    o(ans);putchar('\n');
    return 0;
}


/*struct edge{
    long long to,next,value;
}e[maxn];
long long first[maxn]={0},cntedge=0;
void addedge(long long fr,long long to,long long value){
    e[cntedge++]={to,first[fr],value};first[fr]=cntedge-1;
    swap(fr,to);
    e[cntedge++]={to,first[fr],0};first[fr]=cntedge-1;
}*/
