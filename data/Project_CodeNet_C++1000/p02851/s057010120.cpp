#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, K, ans=0, tmp=0;
vector<ll> A;
map<ll,ll> B;

signed main(){
    cin >> N >> K;
    A.push_back(0);
    B[0]++;
    if(K>N) {
        for(int i=0;i<N;i++) {
            ll a;
            cin >> a;
            a--;
            a %= K;
            tmp += a;
            tmp %= K;
            ans += B[tmp];
            A.push_back(tmp);
            B[tmp]++;
        }
    }
    else {
        for(int i=0;i<K-1;i++) {
            ll a;
            cin >> a;
            a--;
            a %= K;
            tmp += a;
            tmp %= K;
            ans += B[tmp];
            A.push_back(tmp);
            B[tmp]++;
        }
        for(int i=0;i<N-K+1;i++) {
            B[A[i]]--;
            ll a;
            cin >> a;
            a--;
            a %= K;
            tmp += a;
            tmp %= K;
            ans += B[tmp];
            A.push_back(tmp);
            B[tmp]++;
        }
    }
    cout << ans << endl;
    return 0;
}