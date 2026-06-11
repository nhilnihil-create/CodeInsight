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
    ll N,rs=0,max=0;
    cin >> N;
    vector<ll> H(N);

    for(ll i = 0;i < N;i++)
        cin >> H.at(i);

    for(ll i = 0;i < N -1;i++){
        if(H.at(i) >= H.at(i+1)){
            rs++;
        }else{
            if(rs > max)
                max = rs;
            rs = 0;
        }
        if(i == N -2){
            if(rs > max)
                max = rs;
        }
    }

    cout << max << endl;    

}