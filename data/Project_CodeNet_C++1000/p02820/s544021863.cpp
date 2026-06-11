#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const int MOD=998244353;
const int N=2e5+5;



int main(){
    int N, K; cin >> N >> K;
    ll R, S, P; cin >> R >> S >> P;
    string T; cin >> T;
    vi cnt(3, 0);
    vector<vi> db_cnt(K, vi(3, 0));
    vi prev_val(K, -1);
    vi f(K, 0);
    for(int i=0; i<N; i++){
        int val;
        switch (T[i]){
            case 'r' : 
                val=0;
                break;
            case 's' :
                val=1;
                break;
            case 'p' :
                val=2;
                break;
        }
        cnt[val]++;
        if(i < K) continue;
        if(T[i] == T[i-K]){
            prev_val[i%K]=val;
            if(f[i%K] == 0){
                f[i%K]++;
                db_cnt[i%K][val]+=2;
            }
            else db_cnt[i%K][val]++;
        }
        else{
            if(f[i%K]){
                cnt[prev_val[i%K]]-=db_cnt[i%K][prev_val[i%K]]/2;
                db_cnt[i%K][prev_val[i%K]]=0;
                f[i%K]=0;
            }
        }
    }
    for(int i=0; i<K; i++){
        if(f[i%K]) cnt[prev_val[i%K]]-=db_cnt[i%K][prev_val[i%K]]/2;
    }
    ll res;
    res=cnt[0]*P+cnt[1]*R+cnt[2]*S;
    printf("%lld\n", res);
    return 0;
}