#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll h,w;cin>>h>>w;
   vector<string>s(h);
   vector<vector<ll>>tmp(h,vector<ll>(w,0));
    for (int i = 0; i < h; ++i) {
        cin >>s[i];
    }
    for (int i = 0; i < h; ++i) {
        ll now=0;vector<ll>memo;
        for (int j = 0; j < w; ++j) {
            if(s[i][j]=='.')now++;
            else {
                memo.push_back(now);
                now=0;
            }
        }
        memo.push_back(now);
        ll k=0;
        for (int j = 0; j < w; ++j) {
            if(s[i][j]=='.')tmp[i][j]+=memo[k];
            else k++;
        }
    }
    for (int i = 0; i < w; ++i) {
        ll now=0;vector<ll>memo;
        for (int j = 0; j < h; ++j) {
            if(s[j][i]=='.')now++;
            else {
                memo.push_back(now);
                now=0;
            }
        }
        memo.push_back(now);
        ll k=0;
        for (int j = 0; j < h; ++j) {
            if(s[j][i]=='.')tmp[j][i]+=memo[k];
            else k++;
        }
    }
    ll ans=0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
           ans=max(ans,tmp[i][j]-1);
        }
    }
    cout <<ans <<endl;
    return 0;
}
