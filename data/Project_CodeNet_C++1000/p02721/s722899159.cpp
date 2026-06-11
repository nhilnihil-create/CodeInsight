#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,k,c,l[N],r[N],idxl[N],idxr[N];
char a[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k>>c;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1,prv=-1e9,cur=0;i<=n;i++){
        idxl[i]=prv;
        if(a[i]=='x'){
            l[i]=cur;
            continue;
        }
        if(i-prv>c){
            cur++;
            prv=i;
            l[i]=cur;
        }
    }
    for(ll i=n,nxt=1e9,cur=0;i>=1;i--){
        idxr[i]=nxt;
        if(a[i]=='x'){
            r[i]=cur;
            continue;
        }
        if(nxt-i>c){
            cur++;
            nxt=i;
            r[i]=cur;
        }
    }
    for(ll i=1;i<=n;i++){
        ll L=idxl[i],R=idxr[i];
        if(L==-1e9 || R==1e9){
            if(L==-1e9 && R==1e9)cout<<i<<"\n";
            else if(L==-1e9){
                if(r[R]<k)cout<<i<<"\n";
            }
            else{
                if(l[L]<k)cout<<i<<"\n";
            }
        }
        else{
            if(abs(R-L)>c){
                if(l[L]+r[R]<k)cout<<i<<"\n";
            }
            else{
                if(l[L]+r[R]<k+1)cout<<i<<"\n";
            }
        }
    }
}