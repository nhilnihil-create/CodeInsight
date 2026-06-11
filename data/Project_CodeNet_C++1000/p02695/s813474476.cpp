#include<bits/stdc++.h>
using namespace std;
const int  N = 11;
typedef struct query{
        int a,b,c,d;
}query;
int n,m,q,a,b,c,d,f[N],mx=0;
query e[55];
void recur(int idx,int val){
        if(idx==n){
                //for(int i=0;i<n;i++) cout<<f[i]<<" "; cout<<endl;
                int res=0;
                for(int i=0;i<q;i++){ if((f[e[i].b]-f[e[i].a])==e[i].c) res+=e[i].d; }
                //cout<<res<<endl;
                mx=max(mx,res); return;
        }
        for(int i=val;i<=m;i++){
                f[idx]=i;
                recur(idx+1,f[idx]);
        }
}

void solve(){
recur(0,1);
cout<<mx<<endl;
}
int main(){
        cin>>n>>m>>q;
        for(int i=0;i<q;i++){
                cin>>a>>b>>c>>d;
                e[i]={--a,--b,c,d};
        }
        solve();
}
