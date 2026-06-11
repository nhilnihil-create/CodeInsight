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

ll digitnum(ll N){
    ll count = 0,x,hako;
    for(ll i = 1;i <= N;i++){
        x = 0;
        hako = i;
        while(hako > 0){
            hako /= 10;
            x++;
        }
        if(x % 2 != 0)
            count++;
    }

    return count;

}

int main(){
    ll N,ans=0;
    cin >> N;

    ans = digitnum(N);

    cout << ans << endl;
    
    return 0;
}