#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,j,n) for (int i = j; i < (n); ++i)
#define SORT(a) sort(a.begin(),a.end())
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(){
    ll n;
    cin >> n;
    vector<ll> C(n,0),D(n+1,0);
    rep(i,n){
        ll ci; cin >> ci;
        ci--;
        C[ci]++;
        D[C[ci]]++;
    } 

    vector<ll> S(n+1,0);
    REP(i,1,n+1) S[i] = S[i-1] + D[i];

    REP(k,1,n+1){
        ll low = 0,high = n+1;
        while(high-low>1){
            ll x = (low+high)/2;
            if(S[x] >= k*x) low=x;
            else high = x;
        }
        cout<<low<<endl;
    }


}