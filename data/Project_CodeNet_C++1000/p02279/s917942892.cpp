#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

#define NIL -1

struct Node{
    int parent, leftChild, rightSibling;
};

void getDepth(int *arr, Node *nodes, int label, int depth);
std::string getProperty(Node node);
std::vector<int> getChildren(Node *nodes, int label);

int main(int argc, char** argv) {
    Node* nodes;
    int len, *depth, root = NIL;

    scanf("%d", &len);
    nodes = (Node *) calloc(sizeof(Node), len + 1);
    depth = (int *) calloc(sizeof(int), len + 1);

    for (int i = 0; i < len; i++) {
        nodes[i].parent = nodes[i].leftChild = nodes[i].rightSibling = NIL;
    }

    for (int i = 0; i < len; i++) {
        int label, degree, child1 = NIL, child2 = NIL;
        scanf("%d %d", &label, &degree);

        for (int j = 0; j < degree; j++) {
            scanf("%d", &child1);

            nodes[child1].parent = label;

            if (j == 0) {
                nodes[label].leftChild = child1;
            } else {
                nodes[child2].rightSibling = child1;
            }

            child2 = child1;
        }
    }

    for (int i = 0; i < len; i++) {
        if (nodes[i].parent == NIL) {
            root = i;
            break;
        }
    }

    getDepth(depth, nodes, root, 0);

    for (int i = 0; i < len; i++) {
        printf("node %d: parent = %d, depth = %d, ", i, nodes[i].parent, depth[i]);
        std::cout << getProperty(nodes[i]) << ", ";

        std::vector<int> children = getChildren(nodes, i);
        std::cout << "[";
        if (children.size() > 0) {
            std::cout << children[0];
        }
        if (children.size() > 1) {
            for (std::vector<int>::iterator it = children.begin() + 1; it != children.end(); it++) {
                std::cout << ", " << *it;
            }
        }
        std::cout << "]" << std::endl;
    }

    free(nodes);
    free(depth);
    return 0;
}

void getDepth(int *arr, Node *nodes, int label, int depth) {
    arr[label] = depth;

    if (nodes[label].leftChild != NIL) {
        getDepth(arr, nodes, nodes[label].leftChild, depth + 1);
    }

    if (nodes[label].rightSibling != NIL) {
        getDepth(arr, nodes, nodes[label].rightSibling, depth);
    }
}

std::string getProperty(Node node) {
    if (node.parent == NIL) {
        return "root";
    } else {
        if (node.leftChild == NIL) {
            return "leaf";
        } else {
            return "internal node";
        }
    }
}

std::vector<int> getChildren(Node *nodes, int label) {
    std::vector<int> results;
    Node node = nodes[label];

    if (node.leftChild != NIL) {
        results.push_back(node.leftChild);
        node = nodes[node.leftChild];

        while (node.rightSibling != NIL) {
            results.push_back(node.rightSibling);
            node = nodes[node.rightSibling];
        }
    }

    return results;
}

