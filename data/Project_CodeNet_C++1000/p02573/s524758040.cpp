#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define mem0(x) memset(x,0,sizeof(x))
#define meminf(x) memset(x,0x3f,sizeof(x))
#define VI vector<int>
#define VL vector<ll>
using namespace  std;

const int N = 2e5+5;
int s[N];
void initset(int n){
    rep(i,1,n){
        s[i] = i;
    }
}
int getfa(int x){
    if(s[x]==x){
        return x;
    }else{
        return s[x] = getfa(s[x]);
    }
}
void merge(int x,int y){
    int fx = getfa(x),fy = getfa(y);
    if(fx!=fy){
        s[fx] = fy;
    }
}
int num[N];
int main(){
    ios::sync_with_stdio(0);
    int n,m;cin>>n>>m;
    initset(n);
    rep(i,1,m){
        int a,b;cin>>a>>b;
        merge(a,b);
    }
    int cnt= 0,ans = 0;
    rep(i,1,n){
        num[getfa(i)]++;
        //cout<<"id:"<<i<<"s[i]:"<<s[i]<<"num:"<<num[s[i]]<<endl;;
        ans = max(ans,num[getfa(i)]);
    }

    cout<<ans;
}
