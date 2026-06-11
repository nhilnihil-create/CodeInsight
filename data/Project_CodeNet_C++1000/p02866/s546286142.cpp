#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
//a^n modをO(logN)で計算
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main(){
    int64_t n;
    cin>>n;
    map<int64_t,int64_t> p;
    vector<int64_t> d(n);
    int max=0;
    rep(i,n){
        cin>>d[i];
        if(d[i]>max){
            max=d[i];
        }
        p[d[i]]++;
    }
    rep(i,max+1){
        
        if(p[d[i]]==0 || p[0]!=1 || d[0]!=0){
            cout<<0<<endl;
            return 0;
        }
    }
    int64_t ans=1;
    int MOD=998244353;
    for(int i=0;i<max;i++){
        ans = ((ans%MOD)*modpow(p[i],p[i+1],MOD))%MOD;
    }
    cout<<ans<<endl;
}