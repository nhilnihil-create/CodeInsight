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
    ll h,w;cin >>h>>w;
    vector<string>s(h);
    for (int i = 0; i < h; ++i) {
        cin >>s[i];
    }
    vector<vector<ll>>cnt(h+1,vector<ll>(w+1,0));
    for (int i = 0; i < h; ++i) {
        ll now=0;
        for (int j = 0; j < w; ++j) {
            if(s[i][j]=='.')now++;
            else {
                cnt[i][j]=now;
                now=0;
            }
        }
        cnt[i][w]=now;
        ll k=0;
        for (int j = w; j>=0; --j) {
            if((j<w&&s[i][j]=='#')||j==w){
                k=cnt[i][j];
                cnt[i][j]=0;
            }
            else {
                cnt[i][j]+=k;
            }
        }
    }
    for (int i = 0; i < w; ++i) {
        ll now=0;
        for (int j = 0; j < h; ++j) {
            if(s[j][i]=='.')now++;
            else {
                cnt[j][i]=now;
                now=0;
            }
        }
        cnt[h][i]=now;
        ll k=0;
        for (int j = h; j>=0; --j) {
            if((j<h&&s[j][i]=='#')||j==h){
                k=cnt[j][i];
                cnt[j][i]=0;
            }
            else {
                cnt[j][i]+=k;
            }
        }
    }
    ll ans=0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ans=max(ans,cnt[i][j]);
        }
    }
    ans--;
    cout <<ans <<endl;
    return 0;
}