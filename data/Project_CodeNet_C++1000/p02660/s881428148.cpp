#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

vector<pair<ll, ll> > prime_factorize(ll N) {
    vector<pair<ll, ll> > res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back(make_pair(a,ex));
    }

    // 最後に残った数について
    if (N != 1) res.push_back(make_pair(N,1));
    return res;
}

int main(){
    ll n;
    cin >> n;

    const auto &res=prime_factorize(n);

    ll ans=0;
    for(auto p: res){
        ll tmp=1,cnt=1;
        while(tmp<=p.second){
            cnt++;
            tmp+=cnt;
        }
        cnt--;
        ans+=cnt;
    }
    cout << ans << endl;
}