#include <iostream>
#include <cmath>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

#define rep(i,n) for(int i=0;i!=n;++i)

using namespace std;

typedef long long ll;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main(){
    int N;
    scanf("%d",&N);
    map<string,int> mp;
    string str;

    COMinit();

    ll count=0;
    
    for(int i=0;i!=N;++i){
        cin>>str;
        sort(str.begin(),str.end());
        map<string,int>::iterator it=mp.find(str);
        if(it!=mp.end()){
            ++(it->second);
        }else{
            mp.insert(make_pair(str,1));
        }
    }
/*
    for(map<string,int>::iterator it=mp.begin();it!=mp.end();++it){
        cout<<it->first<<":"<<it->second<<endl;
    }
*/
    
    for(map<string,int>::iterator it=mp.begin();it!=mp.end();++it){
        ll a=it->second;
        count+=a*(a-1)/2;
    }

    cout<<count<<endl;

}