#include <atcoder/all>
#include <bits/stdc++.h>


using namespace std;


int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d%d", &N, &M);

    atcoder::dsu disjointSet(N);

    for (int i = 0; i < M; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        
        disjointSet.merge(u-1, v-1);
    }

    int ans = -1;
    for (int i = 0; i < N; ++i) {
        if (i == disjointSet.leader(i)) ans++;
    }

    printf("%d\n", ans);
    return 0;
}
