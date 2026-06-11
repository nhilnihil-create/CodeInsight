#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=0;
vector<ll> A;
set<ll> S;

signed main(){
    cin >> N;
    A.resize(N+2);
    A[0]=0;
    A[N+1]=N+1;
    for(int i=1;i<=N;i++) {
        ll a;
        cin >> a;
        A[a] = i;
    }
    S.insert(N+2);
    S.insert(N+1);
    S.insert(0);
    S.insert(-1);
    S.insert(A[N]);
    for(int i=N-1;i>0;i--) {
        set<ll>::iterator idu1 = S.lower_bound(A[i]);
        set<ll>::iterator idu2 = idu1;
        idu2++;
        set<ll>::iterator idl1 = idu1;
        idl1--;
        set<ll>::iterator idl2 = idl1;
        idl2--;
        S.insert(A[i]);
        if(*idl2!=-1) ans += i*(*idl1-*idl2)*(*idu1-A[i]);
        if(*idu2!=N+2) ans += i*(*idu2-*idu1)*(A[i]-*idl1);
    }
    cout << ans << endl;
    return 0;
}