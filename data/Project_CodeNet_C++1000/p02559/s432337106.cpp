#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int n,q;
typedef long long ll;
#define int ll
int bit[N];
void update(int x,int v){
    x++;
    while(x<=n){
        bit[x]+=v;
        x+=x&-x;
    }
}
int query(int x){
    x++;
    int res=0;
    while(x>0){
        res+=bit[x];
        x-=x&-x;
    }
    return res;
}
signed main(){
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>n>>q;
    for(int x=0;x<n;x++){
        int v;cin>>v;
        update(x,v);
    }
    while(q--){
        int mode;
        cin>>mode;
        if(mode==0){
            int x,v;cin>>x>>v;
            update(x,v);
        }
        else{
            int l,r;cin>>l>>r;
            cout<<query(r-1)-query(l-1)<<"\n";
        }
    }
}