#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll n,k;cin >>n>>k;
    ll r,s,p;cin >>r>>s>>p;
    string t;cin >>t;
    ll ans=0;
    vector<ll>pre(n,0);
    for (int i = 0; i < n; ++i) {
        if(t[i]=='r') {
            if (i < k) {
                ans+=p;
                pre[i]=1;
            }
            else {
                if(t[i]==t[i-k]) {
                    if (!pre[i - k]) {
                        ans += p;
                        pre[i]=1;
                    }
                }
                else {
                    ans+=p;
                    pre[i]=1;
                }
            }
        }
        if(t[i]=='s') {
            if (i < k) {
                ans+=r;
                pre[i]=1;
            }
            else {
                if(t[i-k]==t[i]){
                    if(!pre[i-k]) {
                        ans += r;
                        pre[i]=1;
                    }
                }
                else {
                    ans+=r;
                    pre[i]=1;
                }
            }
        }
        if(t[i]=='p') {
            if (i < k) {
                ans+=s;
                pre[i]=1;
            }
            else {
                if(t[i]==t[i-k]){
                    if(!pre[i-k]) {
                        ans += s;
                        pre[i]=1;
                    }
                }
                else {
                    ans+=s;
                    pre[i]=1;
                }
            }
        }
//        cout <<ans <<endl;
    }
    cout <<ans <<endl;
    return 0;
}