#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const int MOD=1e9+7;
const int N=2e5+5;


int main(){
    ll A, B, K; cin >> A >> B >> K;
    ll res1, res2;
    if(A >= K){
        res1=A-K;
        res2=B;
    }
    else{
        res1=0;
        res2=max(0LL, B-(K-A));
    }
    cout << res1 << " " << res2 << endl;
    return 0;
}