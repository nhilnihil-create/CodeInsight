#include<cstdio>
#define root 1
#define leaf 2
#define internal 3

const int maxn = 1e5 + 5;

struct Node{
    int parent;
    int down;
    int right;
};

Node Tree[maxn * 20];
int input[maxn];

void init(int n){
    for(int i = 0; i < n; i ++){
        Tree[i].parent = -1;
        Tree[i].down = -1;
        Tree[i].right = -1;
    }
}

void build(int n){
    for(int ii = 0; ii < n; ii ++){
        int k, x, i;
        scanf("%d%d", &i, &k);
        if(k){
            scanf("%d", &x);
            Tree[i].down = x;
            Tree[x].parent = i;
            for(int j = 1; j < k; j ++){
                int xx;
                scanf("%d", &xx);
                Tree[xx].parent = i;
                Tree[x].right = xx;
                x = xx;
            }
        }
    }
}

int depth(int now){
    int dep = 0;
    while(Tree[now].parent != -1){
        dep += 1;
        now = Tree[now].parent;
    }
    return dep;
}

int part(int now){
    if(Tree[now].parent == -1)
        return root;
    else{
        if(Tree[now].down == -1)
            return leaf;
        else
            return internal;
    }
}

void print(int now){
    printf("node %d: parent = %d, depth = %d, ", now, Tree[now].parent, depth(now));
    if(part(now) == root)
        printf("root, [");
    else if(part(now) == leaf)
        printf("leaf, [");
    else
        printf("internal node, [");
    if(Tree[now].down != -1){
        for(now = Tree[now].down; now != -1; now = Tree[now].right){
            printf("%d", now);
            if(Tree[now].right != -1)
                printf(", ");
        }
    }
    puts("]");
}

int main(){
    int n;
    scanf("%d", &n);
    init(n);
    build(n);
    for(int i = 0; i < n; i ++){
        print(i);
    }
    return 0;
}

