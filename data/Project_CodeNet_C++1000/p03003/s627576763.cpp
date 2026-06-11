#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
int mem[2003][2003][5];
vector<int> v1, v2;
int solve(int a, int b, int right=0) {
    if(a == v1.size() || b == v2.size())
        return right == 0;

    int &ret = mem[a][b][right];
    if(~ret) return ret;
    ret = 0;
    if(v1[a] == v2[b]) ret += solve(a + 1, b + 1);
    if(right == 1 || right == 0) ret += solve(a + 1, b, 1);
    ret %= mod;
    if(right == 2 || right == 0) ret += solve(a, b + 1, 2);
    ret %= mod;
    if(right == 0) ret += solve(a + 1, b + 1);
    ret %= mod;
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
#endif

    memset(mem, -1, sizeof(mem));
    int n, m;
    scanf("%d %d", &n, &m);
    v1.resize(n);
    for(int i=0; i<n; i++)
        scanf("%d", &v1[i]);
    v2.resize(m);
    for(int i=0; i<m; i++)
        scanf("%d", &v2[i]);
    printf("%d\n", solve(0, 0));


    return 0;
}