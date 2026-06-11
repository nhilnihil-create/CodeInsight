#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    vector<vector<ll>>cnt(10,vector<ll>(10,0));
    ll n;cin >>n;
    for (int i = 1; i <=n; ++i) {
        int b=i%10;
        int keta;
        if(i<10)keta=0;
        else if(i<100)keta=1;
        else if(i<1000)keta=2;
        else if(i<10000)keta=3;
        else if(i<100000)keta=4;
        else keta=5;
        ll d=1;
        for (int i = 0; i < keta; ++i) {
            d*=10;
        }
//        cout <<d<<endl;
        int f=i/d;
        cnt[f][b]++;
    }
    ll ans=0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            ans+=cnt[i][j]*cnt[j][i];
        }
    }
    cout <<ans <<endl;
    return 0;
}

