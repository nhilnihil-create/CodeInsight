#include <cstdio>

typedef struct Node {
    int id;
    int d;
    int f;
    int count;
} Node;


int count(int id, int now, Node *node, int a[101][100]){
    if(node[id].d == 0) node[id].d = now;
    else return now - 1;
    if(node[id].f != 0) return now - 1;
    for(int i = 0; i < node[id].count; ++i){
        int nextId = a[id][i];
        now = count(nextId, now + 1, node, a);
    }
    node[id].f = now + 1;
    return node[id].f;
}

int main(){
    int n;
    std::scanf("%d", &n);
    Node node[101];
    int a[101][100];
    for(int i = 1; i <= n; ++i){
        int id;
        std::scanf("%d", &id);
        node[id].id = id;
        std::scanf("%d", &node[id].count);
        for(int j = 0; j < node[id].count; ++j){
            std::scanf("%d", &a[id][j]);
        }
    }
    int now = 0;
    for(int i = 1; i <= n; ++i){
        now = count(i, now + 1, node, a);
    }
    for(int i = 1; i <= n; ++i){
        std::printf("%d %d %d\n", node[i].id, node[i].d, node[i].f);
    }

    return 0;
}

