#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e10;

int main(){
    ll n=0;
  	cin >> n;
    auto a = vector<ll>(n,0);
    for(auto &i:a) cin >> i;
    auto ans = 0;
    for(auto &i:a) ans^=i;
    cout << (ans==0?"Yes":"No");
    return 0;
}