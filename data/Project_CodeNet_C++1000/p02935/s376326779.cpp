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
    int N;
    cin >> N;
    vector<double> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(ALL(v));
    double ans = (v[0] + v[1]) / 2.0;
    for (int i = 2; i < N; i++) {
        ans = (ans + v[i]) / 2.0;
    }

    printf("%32.18f\n", ans);

}