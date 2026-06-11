#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
const int N=5e5+5;
int n,q;

ll bit[N];
void update(int i,ll x){
    i++;
    while(i<=n){
        bit[i]+=x;
        i+=(i&-i);
    }
}

ll query(int i){
    ll res=0;
    while(i>0){
        res+=bit[i];
        i-=(i&-i);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        update(i,x);
    }
    ll mode,x,y;
    while(q--){
        cin>>mode>>x>>y;
        if(mode==0){
            update(x,y);
        }
        else{
            cout<<query(y)-query(x)<<endl;
        }
    }
}
