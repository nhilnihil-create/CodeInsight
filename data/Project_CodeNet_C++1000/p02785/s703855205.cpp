#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include <iomanip>
#include <bits/stdc++.h>
#include <fstream>
#include <map>
using namespace std;
typedef long long ll;
//#define INF 1000000000000 //10^12:極めて大きい値,∞
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main(){
    ll N, K, temp;
    vector<ll> H;
    cin >> N >> K;
    REP(i,N){
        cin >> temp;
        H.push_back(temp);
    }
    if(N<=K){
        cout << 0 << endl;
        return 0;
    }
    sort(H.begin(), H.end());
    ll ans = 0;
    FOR(i, 0, N-(K+1)){
        ans += H[i];
    }
    cout << ans << endl;
    return 0;
}