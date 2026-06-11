#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int parent = -1;
    int depth;
    vector<int> child;
};

class Tree{
    int root = -1;
    vector<Node> node;
    void calc_root(){
        int i = 0;
        for (int i = 0; ; i++) {
            if (node[i].parent == -1) {
                root = i;
                return;
            }
        }
    }
    void calc_all_depth(int id, int depth){
        node[id].depth = depth;
        for (int i = 0; i < node[id].child.size(); i++) {
            calc_all_depth(node[id].child[i], depth + 1);
        }
    }
public:
    Tree(int n){
        node.resize(n);
    }
    void input_child(int id, int c){
        node[id].child.push_back(c);
        node[c].parent = id;
    }
    void calc_depth(){
        calc_root();
        calc_all_depth(root, 0);
    }
    void print_node(){
        for (int i = 0; i < node.size(); i++) {
            cout << "node " << i << ": parent = " << node[i].parent;
            cout << ", depth = " << node[i].depth << ", ";
            if (node[i].parent == -1) {
                cout << "root";
            } else if (!node[i].child.empty()) {
                cout << "internal node";
            } else {
                cout << "leaf";
            }
            cout << ", [";
            for (int j = 0; j < node[i].child.size(); j++) {
                cout << node[i].child[j];
                cout << (j < node[i].child.size() - 1 ? ", " : "");
            }
            cout << "]" << endl;
        }
    }
};

int main(){
    int n;
    cin >> n;
    Tree T(n);
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            T.input_child(id, c);
        }
    }
    T.calc_depth();
    T.print_node();
    return 0;
}