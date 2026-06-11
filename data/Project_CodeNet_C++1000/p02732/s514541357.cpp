#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll combi(ll n, ll r) {
    ll res = 1;
    for (ll i = n; n - r < i; --i) {
        res = res*i;
    }
    for (ll i = 1 ; i < r + 1; ++i) {
        res = res / i;
    }
    return res;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N,0);
    vector<ll> S(N,0);
    for(ll i=0;i<N;i++){
        ll a;cin>>a;
        A[i]=a;
        S[--a]++;
    }
    ll sum=0;
    for(ll i=0;i<N;i++){
        sum+=combi(S[i],2);
    }
    for(ll i=0;i<N;i++){
        ll index=--A[i];
        cout<<sum-combi(S[index],2)+combi(S[index]-1,2)<<endl;
    }
    return 0;
}