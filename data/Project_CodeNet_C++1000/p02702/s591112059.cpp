#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=2019;

ll modpow(int a, int n){
    ll res=1;
    while(n > 0){
        if(n & 1) res=res*a%MOD;
        a=a*a%MOD;
        n>>=1;
    }
    return res;
}

int main(){
    string S; cin >> S;
    vi cnt(2019, 0);
    cnt[0]++;
    ll sum=0;
    for(int i=S.size()-1; i>=0; i--){
        sum=(sum+(S[i]-'0')*modpow(10, S.size()-1-i)%MOD)%MOD;
        cnt[sum]++;
    }
    ll res=0;
    for(int i=0; i<2019; i++){
        res+=cnt[i]*(cnt[i]-1)/2;
    }
    cout << res << endl;
    return 0;
}