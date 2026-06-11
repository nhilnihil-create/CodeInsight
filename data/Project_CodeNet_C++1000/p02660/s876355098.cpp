#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
#include<utility>
#include<cstdio>
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const long long INF = 1LL<<60;

typedef pair<ll,ll> Pair;
int main(){

ll N;

cin >> N;

vector<Pair> fs;

for(ll i = 2;i*i <= N;++i ){

    ll cnt = 0;

    while(N%i==0){
        N/=i;
        ++cnt;
    }
        fs.emplace_back(i,cnt);
}

if(N!=1) fs.emplace_back(N,1);

ll ans = 0;

for(Pair p : fs){

    ll cnt = p.second;
    ll x = 1;
    while(x <= cnt){
        cnt -= x;
        ++ans;
        ++x;
    }
}

cout << ans << endl;

return 0;

}
