#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    ll N,K;
    cin>>N>>K;
  	ll a=min(abs(N-N/K*K),abs(N-N/K*K-K));
    cout<<min(a,abs(N-N/K*K+K))<<endl;
}

