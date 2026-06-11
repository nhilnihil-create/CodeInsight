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
ll sum = 0;

cin >> N;

vector<ll> a(N);

for(ll i = 0;i < N;++i){
    cin >> a[i];
    sum ^= a[i];
}

for(ll i = 0;i < N;++i) a[i] ^= sum;

for(ll i = 0;i < N;++i) cout << a[i] << endl;

return 0;

}
