#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
const int INFTY =2147483647;
int n,m,q,a[60],b[60],c[60],d[60],ans=0;
int keisan(int x[]){
    int k=0;
    REP(i,q){
        if(x[b[i]-1]-x[a[i]-1]==c[i]) k+=d[i];
    }
    return k;
}
void solve(int p,int x[]){
    if(p==0){
        for(int i=1;i<=m;i++){
            x[p]=i;
            solve(p+1,x);
        }
    }
    else if(p==n){
        ans=max(keisan(x),ans);
    }
    else{
        for(int i=x[p-1];i<=m;i++){
            x[p]=i;
            solve(p+1,x);
        }
    }
}
int main(){
    int x[11]={};
    cin>>n>>m>>q;
    REP(i,q)cin>>a[i]>>b[i]>>c[i]>>d[i];
    solve(0,x);
    cout<<ans<<endl;
}