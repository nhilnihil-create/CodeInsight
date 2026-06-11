#include <bits/stdc++.h>
using namespace std;
#define NIL 2000000

int get_depth(int node_id, vector<int> &parent) {
    int parent_id = parent.at(node_id);
    if (parent_id == NIL)
        return 0;
    return get_depth(parent_id, parent) + 1;
}

void print_children(int node_id, vector<int> &left, vector<int> &right) {
    int left_c = left.at(node_id);

    if (left_c != NIL) {
        cout << left_c;
        int right_c = right.at(left_c);
        while (right_c != NIL) {
            cout << ", " << right_c;
            right_c = right.at(right_c);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> parent(n, NIL), left(n, NIL), right(n, NIL);

    for (int i = 0; i < n; i++) {
        int node;
        cin >> node;

        int k;
        cin >> k;
        if (k) {
            vector<int> children(k);
            for (int j = 0; j < k; j++)
            {
                cin >> children.at(j);
            }
            for (int c : children) {
                parent.at(c) = node;
            }
            left.at(node) = children.at(0); // 最も左の子
            
            if (k > 1) {
                for (int j = 0; j < k - 1; j++) {
                    right.at(children.at(j)) = children.at(j + 1); // すぐ右の子
                }
            }
        }
        
    }

    for (int node_i = 0; node_i < n; node_i++) {
        // node_id
        cout << "node " << node_i << ": ";
        
        // parent
        cout << "parent = ";
        if (parent.at(node_i) == NIL)
            cout << -1;
        else
            cout << parent.at(node_i);
        cout << ", ";

        // depth
        cout << "depth = ";
        cout << get_depth(node_i, parent);
        cout << ", ";

        // type
        if (parent.at(node_i) == NIL)
            cout << "root";
        else if (left.at(node_i) == NIL)
        {
            cout << "leaf";
        }
        else
        {
            cout << "internal node";
        }
        cout << ", ";

        // children
        cout << "[";
        print_children(node_i, left, right);
        cout << "]";
        cout << endl;
    }
}

