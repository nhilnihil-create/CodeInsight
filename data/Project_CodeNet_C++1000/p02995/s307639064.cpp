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

ll mygcd(ll x,ll y){
    if(x <= y){
        if(x == 0)
            return y;
        else
            return mygcd(y%x,x);      
    }else{
        if(y == 0)
            return x;
        else
        {
            return mygcd(y,x%y);
        }
        
    }
}

ll lcdcalc(ll N,ll C,ll D){
    ll c = N / C;
    ll d = N / D;

    ll g = mygcd(C,D);

    ll lcd = C / g * D;

    ll nlcd = N / lcd;

    return N - c - d + nlcd;
    
}

int main(){
    ll A,B,C,D;
    cin >> A >> B >> C >> D;

    cout << lcdcalc(B,C,D) - lcdcalc(A-1,C,D) << endl;

}