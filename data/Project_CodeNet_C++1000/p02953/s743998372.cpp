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
    ll N;
    cin >> N;
    vector<ll>h(N);
    bool fla=true;
    for(ll i = 0;i < N;i++)
        cin >> h.at(i);

    for(ll i = N-1;i > 0;i--){
        if(h.at(i) >= h.at(i-1))
            continue;
        else if(h.at(i) == (h.at(i-1)-1))
            h.at(i-1)--;
        else{
            fla = false;
            break;
        }
        
    }

    if(fla)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}