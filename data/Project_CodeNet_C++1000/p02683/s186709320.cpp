#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

const ll INF=1001001001;

int main(){
    ll n,m,x;
    cin >> n >> m >> x;
    vector<ll> price(n);
    vector<vector<ll>> a(n,vector<ll>(m));
    vector<ll> pr(m,0);
    rep(i,n){
        cin >> price[i];
        rep(j,m){
            cin >> a[i][j];
        }
    }
    ll ans = INF;
    for(ll tmp=1;tmp<(1<<12);tmp++){
        bitset<12> s(tmp);
        bool flag=true;
        ll sum=0;
        rep(i,n){
            if(s.test(i)){
                sum += price[i];
                rep(j,m){
                    pr[j] += a[i][j];
                }
            }
        }
        rep(i,m){
            if(pr[i]<x){
                flag=false;
                break;
            }
        }
        rep(i,m){
            pr[i]=0;
        }
        if(flag){
            ans = min(sum,ans);
        }
    }
    if(ans==INF) cout<< -1 << endl;
    else cout << ans << endl;
}