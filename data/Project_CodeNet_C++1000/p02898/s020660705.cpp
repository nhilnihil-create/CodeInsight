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
    ll N,goukei=0;
    int K;
    cin >> N >> K;
    vector<int>h(N);

    for(ll i=0;i < N;i++){
        cin >> h.at(i);
    }
    
    sort(h.begin(),h.end());
    reverse(h.begin(),h.end());
    
    for(ll i = 0;i < N;i++){
        if(h.at(i) < K)
            break;
        else
            goukei++;
    }

    cout << goukei << endl;
}