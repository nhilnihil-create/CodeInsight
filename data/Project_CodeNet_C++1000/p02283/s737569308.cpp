#include<bits/stdc++.h>


struct node{
    node *left, *right, *parent;
    int key;
};

node *root, *NIL;

void insert(int a){
    node *y = NIL;
    node *x = root;
    node *z;

    z = (node *)malloc(sizeof(node));
    z->key = a;
    z->left = NIL;
    z->right = NIL;

    y = NIL;
    x = root;

    while(x != NIL){
        y = x;
        if(z->key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }

    z->parent = y;

    if(y == NIL){
        root = z;
    }else if(z->key < y->key){
        y->left = z;
    }else{
        y->right = z;
    }



}

int perParse(node *a){
    if(a == NIL){
        return 0;
    }
    //ve.push_back(u);
    std::cout << " " << a->key;
    perParse(a->left);
    perParse(a->right);
}

int inOrder(node *a){
    if(a == NIL){
        return 0;
    }
    inOrder(a->left);

    std::cout << " " << a->key;
    //ve.push_back(u);
    inOrder(a->right);
}

int main(void){
    int n;
    int a;
    std::string str;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> str;
        if(str == "insert"){
            std::cin >> a;
            insert(a);
        }else{
            inOrder(root);
            std::cout << std::endl;
            perParse(root);
            std::cout << std::endl;

        }
    }
    return 0;
}
