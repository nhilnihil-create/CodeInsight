#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = a, i##_len = (b); i < i##_len; ++i)

const ll MOD = 998244353;
const int MAX_N = 100100;
int D[MAX_N];
ll num[MAX_N]; //num[i] := 頂点1との距離がiの頂点が何個あるか
int N;

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) scanf("%d", &D[i]);

    if(D[0] != 0) { printf("0\n"); return 0;}

    for(int i = 0; i < N; ++i) ++num[D[i]];

    ll res = 1LL;

    for(int i = 1; i < N; ++i) res = res*num[D[i]-1]%MOD;

    printf("%lld\n", res);
    return 0;
}