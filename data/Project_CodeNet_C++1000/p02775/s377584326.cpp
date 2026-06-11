#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
    string N;
    cin >> N;
    int L = N.length();

    vector<ll> dp0(L+1), dp1(L+1);
    dp0[0] = 0;
    dp1[0] = 2;
    for (ll i = 1; i < L+1; i++) {
        dp0[i] = min(dp0[i-1], dp1[i-1]) + (N[i-1] - '0');
        if(N[i-1] == '9'){
            dp1[i] = dp1[i-1] + 9 - (N[i-1] - '0');
        }
        else{
            dp1[i] = min(min(dp0[i-1] + (N[i-1] - '0') + 2, dp1[i-1] + (N[i-1] - '0') + 2), dp1[i-1] + 9 - (N[i-1] - '0'));
        }
    }

    printf("%lld\n", min(dp0[L], dp1[L]));

    


}