#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>
#include <utility>
#include <sstream>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) x.begin(),x.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

int main(){ 
    ll N;
    cin >> N;
    vector<ll> A(N);
    set<ll> ss;

    for(ll i = 0;i < N;i++){
        cin >> A.at(i);
        ss.insert(A.at(i));
    }
    
    map<ll,ll>mpa;

    ll goukei = 0;

    for(auto x:ss)
        mpa[x] = 0;

    for(ll i = 0;i < N;i++)
        mpa[A.at(i)]++;
    
    ll ans = 0;

    for(auto x:ss){
        goukei += mpa[x] * (mpa[x] - 1) / 2;
    }

    for(ll i = 0;i < N;i++){
        ll sub = mpa[A.at(i)] - 1; 
        cout << goukei - sub << endl;
    }
    

    
    
}