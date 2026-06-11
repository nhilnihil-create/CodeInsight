#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, P, ans=0, tmp1=0, tmp2=0;
string S;
vector<ll> A;

signed main(){
    cin >> N >> P >> S;
    A.resize(P,0);
    A[0]++;
    tmp1 = 1;
    if(10%P==0) {
        for(int i=0;i<N;i++) {
            ll num = S[N-1-i]-'0';
            if(num%P==0) ans += N-i;
        }
        cout << ans << endl;
        return 0;
    }
    for(int i=0;i<N;i++) {
        ll num = S[N-1-i]-'0';
        num *= tmp1;
        tmp2 += num;
        tmp2 %= P;
        A[tmp2]++;
        tmp1 *= 10;
        tmp1 %= P;
    }
    for(int i=0;i<P;i++) {
        ans += A[i]*(A[i]-1)/2;
    }
    cout << ans << endl;
    return 0;
}