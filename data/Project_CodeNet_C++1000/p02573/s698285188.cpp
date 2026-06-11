#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int par[200001],ran[200001];
void init(int n){                 //忘れない
    rep(i,n+1) par[i]=i,ran[i]=0;
}
int find(int x){
    if(par[x]==x) return x;
    else return par[x]=find(par[x]);
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(ran[x]<ran[y]) par[x]=y;
    else{
        par[y]=x;
        if(ran[x]==ran[y]) ran[x]++;
    }
}
int same(int x,int y){
    return find(x)==find(y);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    init(n);
    rep(i,m) cin>>a>>b,unite(a,b);
    vec num(n+1,0);
    rep1(i,n) num[find(i)]++;
    cout<<*max_element(all(num));
}