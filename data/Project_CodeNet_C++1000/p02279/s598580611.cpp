#include <iostream>
#include <vector>
#define NIL -1
#define MAX 100000+5
#define INF 10000000

struct Node {
    int depth;
    int parent = NIL;
    int child = NIL;
    int sibling = NIL;
};

std::vector<Node> nodes;

void setDepth(int node_num, int depth) {
    nodes.at(node_num).depth = depth;
    if (nodes.at(node_num).sibling != NIL) /* -> */ setDepth(nodes.at(node_num).sibling, depth);
    if (nodes.at(node_num).child != NIL) /* -> */setDepth(nodes.at(node_num).child, depth+1);
    return;
}

void setNode(int node_num, int children[]) {
    if (children[0] != INF) {
        nodes.at(node_num).child = children[0];
        for (int i=0;children[i]!=INF; i++) /* -> */ nodes.at(children[i]).parent = node_num;
        for (int i=0; children[i+1]!=INF; i++) /* -> */nodes.at(children[i]).sibling = children[i+1];
    }
}

std::vector<int> getChildren(int node_num) {
    std::vector<int> children;
    if (nodes.at(node_num).child != NIL) {
        children.push_back(nodes.at(node_num).child);
        node_num = nodes.at(node_num).child;
        while (nodes.at(node_num).sibling != NIL) {
            children.push_back(nodes.at(node_num).sibling);
            node_num = nodes.at(node_num).sibling;
        }
    }
    return children;
}

void output(Node node, int node_num) {
    std::cout << "node " << node_num << ": ";
    std::cout << "parent = " << node.parent << ", ";
    std::cout << "depth = " << node.depth << ", ";
    if (node.parent == NIL) std::cout << "root" << ", ";
    else if (node.child != NIL) std::cout << "internal node" << ", ";
    else /* if (node.child == NIL) */ std::cout << "leaf" << ", ";    
    std::vector<int> children = getChildren(node_num);
    std::cout << "[";
    if (node.child != NIL) {
        for (int i=0; i<children.size()-1; i++) std::cout << children.at(i) << ", ";
        std::cout << children.at(children.size()-1);
    }
    std::cout << "]" << "\n";
}

int main() {
    int total, node_num, children_num;
    int children[MAX];
    std::cin >> total;
    nodes.resize(total);
    for (int i=0; i<total; i++) {
        std::cin >> node_num >> children_num;
        for (int j=0; j<children_num; j++) {
            std::cin >> children[j];
        }
        children[children_num] = INF;
        setNode(node_num, children);
    }
    int root_num;
    for (int i=0; i<total; i++) {
        if (nodes.at(i).parent == NIL) {
            root_num = i;
            break;
        }
    }
    setDepth(root_num, 0);
    
    for (int i=0; i<nodes.size(); i++) output(nodes.at(i), i);
}

