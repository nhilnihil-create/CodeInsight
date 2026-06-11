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

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main(){
    ll N,migi,hidari,d_size;
    cin >> N;
    vector<ll> d(N);

    for(ll i = 0;i < N;i++)
        cin >> d.at(i);

    sort(d.begin(),d.end());
    d_size=d.size();
    migi = d.at((d_size/2)-1);
    hidari=d.at((d_size/2));

    cout << hidari - migi << endl;



    

}