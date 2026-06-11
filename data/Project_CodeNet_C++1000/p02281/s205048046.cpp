#include<bits/stdc++.h>

int NILL = -1;
int a = 0;

struct node{
    int parent, left, right, depth, height;
    node(){
        parent = NILL;
        left = NILL;
        right = NILL;
        depth = NILL;
        height = NILL;
    }
};

std::vector<node> tree;

std::vector<int> ve;

void print(std::vector<int> a){
    for(int i = 0; i < a.size(); i++){
        std::cout << " ";

        std::cout << a[i];
    }
    std::cout << std::endl;
}

int perParse(int u){
    if(u == NILL){
        return 0;
    }
    ve.push_back(u);
    perParse(tree[u].left);
    perParse(tree[u].right);
}

int inOrder(int u){
    if(u == NILL){
        return 0;
    }
    inOrder(tree[u].left);

    ve.push_back(u);
    inOrder(tree[u].right);
}

int postOrder(int u){
    if(u == NILL){
        return 0;
    }
    
    postOrder(tree[u].left);
    postOrder(tree[u].right);
    ve.push_back(u);

}

int main(void){
    int n;
    std::cin >> n;
    tree.resize(n);
    int id, left, right;
    for(int i = 0; i < n; i++){
        std::cin >> id >> left >> right;
        tree[id].left = left;
        tree[id].right = right;
        tree[left].parent = tree[right].parent = id;
    }

    int root;
    for(int i = 0; i < n; i++){
        if(tree[i].parent == -1){
            root = i;
            break;
        }
    }

    std::cout << "Preorder" << std::endl;
    perParse(root);
    print(ve);
    ve.clear();
    
    std::cout << "Inorder" << std::endl;
    inOrder(root);
    print(ve);
    ve.clear();

    std::cout << "Postorder" << std::endl;
    postOrder(root);
    print(ve);
    ve.clear();

    
    return 0;
}
