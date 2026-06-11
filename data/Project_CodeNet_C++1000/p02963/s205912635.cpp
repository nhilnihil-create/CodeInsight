#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll S;
    cin >> S;
    ll X1, X2, X3, Y1, Y2, Y3;
    X1 = 0;
    Y1 = 0;
    X2 = 1000000000;
    Y3 = (S-1)/1000000000 + 1;
    if(S % 1000000000 == 0){
        Y2 = 0;
        X3 = 0;
    }
    else{
        Y2 = 1;
        X3 = X2 * Y3 - S;
    }
    printf("%lld %lld %lld %lld %lld %lld\n", X1, Y1, X2, Y2, X3, Y3);

}