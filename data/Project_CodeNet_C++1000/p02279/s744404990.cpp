#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int parent = -1;
    int depth  = 0;
    vector<int> child;
};

class Tree{
    vector<Node> node;
    void set_depth(int id){
        for (int i = 0; i < node[id].child.size(); i++) {
            node[node[id].child[i]].depth = node[id].depth + 1;
            set_depth(node[id].child[i]);
        }
    }
public:
    Tree(int n) {
        node.resize(n);
    }
    void add_node(int id, const vector<int>& child){
        node[id].child = child;
        for (int i = 0; i < child.size(); i++) {
            node[child[i]].parent = id;
        }
    }
    void calc_depth(){
        int root;
        for (int i = 0; i < node.size(); i++) {
            if (node[i].parent == -1){
                root = i;
                break;
            }
        }
        set_depth(root);
    }
    void print_all(){
        for (int i = 0; i < node.size(); i++) {
            cout << "node " << i << ": parent = " << node[i].parent;
            cout << ", depth = " << node[i].depth;
            cout << ", ";
            if (node[i].parent == -1) {
                cout << "root";
            } else if (node[i].child.size() == 0) {
                cout << "leaf";
            } else {
                cout << "internal node";
            }
            cout << ", [";
            for (int j = 0; j < node[i].child.size(); j++) {
                cout << node[i].child[j];
                if (j < node[i].child.size() - 1) cout << ", ";
            }
            cout << "]";
            cout << endl;
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
        Node n;
        vector<int> child;
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            child.push_back(c);
        }
        T.add_node(id, child);
    }
    T.calc_depth();
    T.print_all();



    return 0;
}