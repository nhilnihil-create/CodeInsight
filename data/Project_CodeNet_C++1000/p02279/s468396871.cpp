#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int parent;
    int number;
    struct Node *left;
    struct Node *right;
};

struct Node * N[100000];
//void show()
//
int getDepth(struct Node *node){

    int count = 0;

    while (node->parent != -1) {
        count++;
        node = N[node->parent];
    }

    return count;
}

int main() {

    struct Node *node1, *node2, *node3, *prev_node, *parent;
    int n, m, node, parent_number, node_count, child_node;

    cin >> n;

    for (int i = 0; i < n; i++) {
        N[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        cin >> parent_number;
        cin >> node_count;

        if (N[parent_number] == NULL) {
            node2 = (struct Node*)malloc(sizeof(struct Node));
            node2->number = parent_number;
            node2->right = NULL;
            node2->left = NULL;
            node2->parent = -1;
            N[parent_number] = node2;
        }

        for (int j = 0; j < node_count; j++) {
            cin >> child_node;
            node1 = (struct Node*)malloc(sizeof(struct Node));
            node1->number = child_node;

            // slibing
            if (j == 0) {
                N[parent_number]->left = node1;
            }
            else {
                prev_node->right = node1;
            }


            // parent
            node1->parent = parent_number;

            prev_node = node1;
            //cout << prev_node->number << endl;

            if (N[child_node] == NULL){

                node1->right = NULL;
                node1->left = NULL;
                N[child_node] = node1;

            }
            //else {

            //}
            //cout << "child node " << parent_number;
            N[child_node]->parent = parent_number;

        }
    }
    for (int i = 0; i < n; i++) {
        struct Node *a = N[i];
        struct Node *b;
        cout << "node " << i << ":";
        cout << " parent = " << a->parent;

        // depth
        //
        cout << ", depth = ";
        cout << getDepth(a);

        // type
        if (a->parent == -1) {
            cout << ", root";
        }
        else if (a->left) {
            cout << ", internal node";
        }
        else if (a->left == NULL) {
            cout << ", leaf";
        }



        cout << ", [";
        b = a->left;
        while (b != NULL){
            cout << b->number;
            b = b->right;
            if (b) {
                cout << ", ";
            }
        }
        cout << "]" ;





        cout << endl;
    }


    return 0;

}
 