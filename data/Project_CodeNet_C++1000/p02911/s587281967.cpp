#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,l,r) for (ll i = (ll)l; i < (ll)(r); i++)

int main(){
    ll N,K,Q; cin >> N >> K >> Q;
    vector<ll> A(N+1,K-Q);
    rep(i,0,Q){
        ll a;
        cin >> a;
        a--;
        A[a]++;
    }
    rep(i,0,N){
        if(A[i]>0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}