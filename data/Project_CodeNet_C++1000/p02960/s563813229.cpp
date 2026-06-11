#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

ll MOD=1000000007;

// a^n mod を計算する
//ただしmとaが互いにその時のみ
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
    string S;
    cin >> S;
    ll N=S.size();
    ll def=0;
    deque<ll> list;
    for(ll i=0;i<N;i++){
        if(S[i]!='?'){
            ll c=S[i]-'0';
            def+=modpow(10,N-i-1,13)*c;
            def%=13;
        }
        else {
            list.emplace_back(modpow(10,N-i-1,13));
        }
    ;}
    ll siz=list.size();
    vector<vector<ll>> dp(siz+1, vector<ll>(13, 0));
    dp[0][def]=1;
    for(ll i=1;i<=siz;i++){
        for(ll j=0;j<10;j++){
            for(ll k=0;k<13;k++){
                dp[i][(k+(j*list[i-1]))%13]+=dp[i-1][k];
                dp[i][(k+(j*list[i-1]))%13]%=MOD;
            }
        ;}
    ;}
    cout<<dp[siz][5]<<endl;
return 0;
}
