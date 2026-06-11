#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r[10],c[10];
ll cntr[(1<<10)],cntc[(1<<10)];
string s[10];
bool rr[10],cc[10];
int main() {
    ll H,W,K;
    cin>>H>>W>>K;
    for(ll i=0;i<H;i++) cin>>s[i];
    ll sum=0;
    for(ll i=0;i<H;i++){
        for(ll j=0;j<W;j++){
            if(s[i][j]=='#'){
                sum++;
            }
        }
    }
    for(ll i=0;i<H;i++) {
        for (ll j = 0; j < W; j++) {
            if (s[i][j] == '#') {
                r[i]++;
            }
        }
    }
    for(ll i=0;i<W;i++){
        for(ll j=0;j<H;j++){
            if(s[j][i]=='#'){
                c[i]++;
            }
        }
    }
    ll limitr=(1<<H);
    for(ll i=0;i<limitr;i++){
        ll temp=i,now=0,k=0;
        while(temp){
            if(temp&1){
                now+=r[k];
            }
            k++;
            temp>>=1;
        }
        cntr[i]=now;
    }
    ll limitc=(1<<W);
    for(ll i=0;i<limitc;i++){
        ll temp=i,now=0,k=0;
        while(temp){
            if(temp&1){
                now+=c[k];
            }
            k++;
            temp>>=1;
        }
        cntc[i]=now;
    }
    ll ans=0;
    for(ll i=0;i<limitr;i++){
        for(ll j=0;j<limitc;j++){
            memset(cc,0,sizeof(cc));
            memset(rr,0,sizeof(rr));
            ll temp=i,k=0;
            while(temp){
                if(temp&1)  rr[k]=1;
                k++;
                temp>>=1;
            }
            temp=j,k=0;
            while(temp){
                if(temp&1)  cc[k]=1;
                k++;
                temp>>=1;
            }
            ll cnt=0;
            for(ll t=0;t<H;t++){
                if(rr[t]){
                    for(ll k=0;k<W;k++){
                        if(cc[k]){
                            if(s[t][k]=='#'){
                                cnt++;
                            }
                        }
                    }
                }
            }
            if(sum-cntr[i]-cntc[j]+cnt==K)  ans++;
        }
    }
    cout<<ans;
    return 0;
}
