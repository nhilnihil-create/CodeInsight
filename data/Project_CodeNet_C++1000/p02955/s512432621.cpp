#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, K, ans=0, tmp=0;
vector<ll> A, B;

void rekkyo(){
    for(int i=1;i*i<=tmp;i++) {
        if(tmp%i==0) {
            if(i*i==tmp) {
                B.push_back(i);
            }
            else {
                B.push_back(i);
                B.push_back(tmp/i);
            }
        }
    }
    sort(B.begin(),B.end());
}

signed main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        tmp += a;
        A.push_back(a);
    }
    rekkyo();
    for(int i=0;i<B.size();i++) {
        vector<ll> C;
        tmp=0;
        for(int j=0;j<A.size();j++) {
            tmp += A[j]%B[i];
            C.push_back(A[j]%B[i]);
        }
        sort(C.begin(),C.end());
        tmp = tmp/B[i];
        ll tmpsum=0;
        for(int j=C.size()-tmp;j<C.size();j++) {
            tmpsum += B[i]-C[j];
        }
        if(tmpsum<=K) ans = B[i];
        //cout << B[i] << " " << tmpsum << endl;
    }
    cout << ans << endl;
    return 0;
}