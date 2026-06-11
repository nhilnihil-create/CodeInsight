#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

int main(){
    ll N; cin >> N;
    ll res=LINF;
    for(ll i=1; i*i<=N; i++){
        if(N%i == 0){
            res=min(res, i-1+N/i-1);
        }
    }
    cout <<res << endl;
    return 0;
}