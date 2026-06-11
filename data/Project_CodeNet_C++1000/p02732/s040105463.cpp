#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)


int main(){
    int N; cin >> N;
    vector<ll> A(N+1);
    map<ll,ll> mp;
    ll sum = 0;
    rep(i,N)
    {
        cin >> A[i];
        mp[A[i]]++;
    }


    for(auto it : mp){
        if(it.second >= 2) sum += (it.second * (it.second - 1) / 2);
    }

    rep(i,N){
        cout << sum - mp[A[i]] + 1 << endl;
    }
}