#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k,q;cin>>k>>q;
    vector<ll> d(k); rep(i,k)cin>>d[i];
    vector<ll> a(k);//本当のa_jはこれにx_iとかいろいろ足す
    a[0]=0;
    for(int i=0; i<k-1; i++){
        a[i+1]=a[i]+d[k];
    }


    for(int i=0; i<q; i++){
        ll n,x,m;cin>>n>>x>>m;
        //繰り上がり回数を数える
        //足してって最後に割ればOK
        //O(n)はだめなので繰り返しはまとめて
        vector<ll> e(k);
        rep(i,k){
            e[i]=(d[i]-1+m)%m+1;
        }//d_iに0もあるらしい
        ll sumc = 0, sump = 0, sumcc = 0, sumpp = 0;
        ll A = (n-1)/k, B=(n-1)%k;
        for(int j=0; j<k; j++){
            sumc += e[j];
            //if(e[j]==0)sumcc++;
            if(j<B){
                sump+=e[j];
                //if(e[j]==0)sumpp++;
            }
        }
        ll sum = sumc*A+sump+x;
        cout<<n-1-(sum/m-x/m)-sumcc*A-sumpp<<endl;
    }

    


    
    return 0;
}