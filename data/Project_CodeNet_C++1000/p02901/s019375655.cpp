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
    ll N, M; cin >> N >> M;
    vector<int> a(M), b(M);
    vector<int> s(M);
    int tmp;
    vector<ll> dp(1<<N, INF/2);
    dp[0] = 0;
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
        s[i] = 0;
        for (int j = 0; j < b[i]; j++) {
            cin >> tmp; tmp--;
            s[i] += (1<<tmp);
        }
        for (int j = 0; j < (1<<N); j++) {
            int g = s[i] | j;
            dp[g] = min(dp[g], dp[j] + a[i]);
        }
    }


    if(dp[(1<<N) - 1] == INF/2){
        printf("%d\n", -1);
    }
    else{
        printf("%lld\n", dp[(1<<N) - 1]);
    }




}