#include <bits/stdc++.h>

const static int MAX = 100000;

std::vector<int> T[MAX];
int parent[MAX], D[MAX];
int N, height;

void setDepth(int node, int d) {
    D[node] = d;
    for (unsigned long i = 0; i < T[node].size(); i++) {
        setDepth(T[node][i], d+1);
    }
}

int main()
{
    std::scanf("%d", &N);
    int node, deg, ch, root = 0;
    for (int i = 0; i < N; i++) {
        parent[i] = -1;
        D[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        std::scanf("%d %d", &node, &deg);
        for (int j = 0; j < deg; j++) {
            std::scanf("%d", &ch);
            parent[ch] = node;
            T[node].push_back(ch);
        }
    }

    for (int i = 0; i < N; i++) {
        if (parent[i] == -1) {
            root = i;
            break;
        }
    }

    setDepth(root, 0);
    for (int i = 0; i < N; i++) {
        std::printf("node %d: parent = %d, depth = %d, ", i, parent[i], D[i]);
        if (i == root) std::printf("root, [");
        else if (T[i].size() == 0) std::printf("leaf, [");
        else std::printf("internal node, [");
        for (int j = 0; j < T[i].size(); j++) {
            if (j) std::printf(", ");
            std::printf("%d", T[i][j]);
        }
        std::printf("]\n");
    }


    return 0;
}

