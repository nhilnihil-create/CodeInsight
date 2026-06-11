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
    ll N,goukei = 0;
    cin >> N;

    vector<ll>L(N);

    for(ll i = 0;i < N;i++)
        cin >> L.at(i);

    sort(L.begin(),L.end());

    for(ll i = 0;i < N - 2;i++){
        for(ll j = i + 1;j < N -1;j++){
            const ll k = lower_bound(ALL(L),L.at(i)+L.at(j))-L.begin();
            ll d = k - j -1;
            goukei += d;
        }
    }

    cout << goukei << endl;
}