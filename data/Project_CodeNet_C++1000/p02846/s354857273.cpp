#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll one = 1;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll t1, t2, a1, a2, b1, b2, c1, c2, d, e;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    c1 = a1 - b1;
    c2 = a2 - b2;
    if(c1 < 0){
        c1 = -c1;
        c2 = -c2;
    }
    d = t1 * c1;
    e = t1 * c1 + t2 * c2;
    if(e > 0){
        printf("%d\n", 0);
    }
    else if(e == 0){
        printf("infinity\n");
    }
    else{
        e = -e;
        if(d % e == 0){
            printf("%lld\n", 2 * (d/e));
        }
        else{
            printf("%lld\n", 1 + 2 * (d/e));
        }
    }

}