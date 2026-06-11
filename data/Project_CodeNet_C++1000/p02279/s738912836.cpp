#include <iostream>
#include <cstdio>

constexpr int MAX_NUM = 100000;

struct Node{int p, l, r;};
int D[MAX_NUM];

Node T[MAX_NUM];

void setDepth(int tgt_id, int cur_depth) {
    D[tgt_id] = cur_depth;
    if (T[tgt_id].l != -1) setDepth(T[tgt_id].l, cur_depth + 1);
    if (T[tgt_id].r != -1) setDepth(T[tgt_id].r, cur_depth);
}

void printNode(int tgt_id) {
    int pid = -1;
    if (T[tgt_id].p != -1) {
        pid = T[tgt_id].p;
    }
    std::printf("node %d: parent = %d, depth = %d, ", tgt_id, pid, D[tgt_id]);
    std::string node_name = "root";
    if ((T[tgt_id].l != -1)) {
        if (pid > -1) node_name = "internal node";
        printf("%s, [", node_name.c_str());
        printf("%d", T[tgt_id].l);
        int c_id = T[tgt_id].l;
        while (T[c_id].r > -1) {
            printf(", %d", T[c_id].r);
            c_id = T[c_id].r;
        }
        printf("]\n");
    }else {
        if (pid > -1) node_name = "leaf";
        printf("%s, [", node_name.c_str());
        printf("]\n");
    }
}

int main(int argc, char** argv) {
    int n, k;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        T[i].p = -1;
        T[i].l = -1;
        T[i].r = -1;
    }
    for (int i = 0; i < n; ++i) {
        int id, k, r, l;
        std::cin >> id >> k;
        for (int j = 0; j < k; j++) {
            std::cin >> r;
            if (j == 0) T[id].l = r;
            else {
                T[l].r = r;
            }
            l = r;
            T[r].p = id;
        }
    }

    int r = -1;
    for (int i = 0; i < n; i++) {
        if (T[i].p == -1) {
            r = i;
        }
    }
    setDepth(r, 0);
    for (int i = 0; i < n; i++) {
        printNode(i);
    }

}
