#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int id, parent_id, depth;
    vector<int> children;
    node(){ parent_id=-1; depth=0; }
};

vector<node> tree;

void calc_depth(node &nd, int current_depth)
{
    nd.depth=current_depth;
    if(nd.children.size()){
        for(auto it=nd.children.begin(); it!=nd.children.end(); it++){
            calc_depth(tree[*it], current_depth+1);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    tree=vector<node>(n);
    for(int i=0; i<n; i++){
        int id; scanf("%d", &id);
        auto it=&tree[id];
        it->id=id;
        int k; scanf("%d", &k);
        for(int j=0; j<k; j++){
            int c; scanf("%d", &c);
            it->children.push_back(c);
            tree[c].parent_id=it->id;
        }
    }

    for(auto it=tree.begin(); it!=tree.end(); it++){
        if(it->parent_id==-1){
            calc_depth(*it, 0);
            break;
        }
    }

    for(auto it=tree.begin(); it!=tree.end(); it++){
        printf("node %d: parent = %d, depth = %d, ", it->id, it->parent_id, it->depth);
        if(it->parent_id==-1){
            printf("root");
        } else if(it->children.size()==0){
            printf("leaf");
        } else{
            printf("internal node");
        }

        printf(", [");
        for(auto jt=it->children.begin(); jt!=it->children.end(); jt++){
            if(jt!=it->children.begin()){
                printf(", ");
            }
            printf("%d", *jt);
        }
        printf("]\n");
    }
    return 0;
}