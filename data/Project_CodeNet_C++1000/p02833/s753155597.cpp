#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const int MOD=1e9+7;

const int N=1e9+5;

int main(){
    ll N; cin >> N;
    ll val_2=0, val_5=0;
    ll cnt=2;
    ll res=0;
    if(N%2 == 0){
        while(N/cnt > 0){
            val_2+=N/cnt;
            cnt*=2;
        }
        cnt=5;
        while(N/cnt > 0){
            val_5+=N/cnt/2;
            cnt*=5;
        }
        res=min(val_2, val_5);
    }
    else res=0;
    cout << res << endl;
    return 0;
}