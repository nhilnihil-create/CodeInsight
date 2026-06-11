#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
const ll MOD=1000000007;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N),B(N);
    rep (i,N){
        cin >> A[i];
    }
    rep (i,N){
        cin >> B[i];
    }
    ll ans=0;
    bool c=true;
    while(c){
        c=false;
        rep (i,N){
            int a=B[(i-1+N)%N]+B[(i+1)%N];
            if (B[i]-A[i]>=a){
                int b=(B[i]-A[i])/a;
                B[i]-=a*b;
                ans+=b;
                c=true;
            }
        }
    }
    if (A==B){
        cout << ans << endl;
    }
    else {
        cout << -1 << endl;
    }
}