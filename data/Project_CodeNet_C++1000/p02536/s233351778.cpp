#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXLEN = 1e5+5;

int parent[MAXLEN];

// find the parent of x
int Find(int x) {
    if (parent[x] == -1) {
        return x;
    }
    // shorten the path to root
    parent[x] = Find(parent[x]);
    return parent[x];
}

// union x and y
void Union(int x, int y) {
    int parentx = Find(x), parenty = Find(y);
    if (parentx != parenty) {
        parent[parenty] = parentx;
    }
}


int main(int argc, char const *argv[])
{
    int nCases = 1;
    //scanf("%d", &nCases);

    for (int iCase = 1; iCase <= nCases; ++iCase) {
        int N, M;
        scanf("%d%d", &N, &M);

        for (int i = 0; i <= N; ++i) {
            parent[i] = -1;
        }

        for (int i = 0; i < M; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            Union(x, y);
        }

        int nRoots = -1;
        for (int i = 1; i <= N; ++i) {
            if (i == Find(i)) nRoots++;
        }

        printf("%d\n", nRoots);
        //printf("Case #%d: %.7lf\n", iCase, ans);
    }

    return 0;
}
