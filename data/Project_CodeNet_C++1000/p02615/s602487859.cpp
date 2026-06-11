#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin>>A[i];

    sort(A.rbegin(), A.rend());

    ll ans=0;
    int t=N-1;
    rep(i, N){
        int lim=2;
        if(i==0) lim=1;
        rep(j, lim){
            if(t>0){
                ans+=A[i];
                t--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}