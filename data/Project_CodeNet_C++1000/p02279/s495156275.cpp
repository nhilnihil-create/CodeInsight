#include<iostream>
#include<vector>
using namespace std;

struct tree{
    int parent;
    int right_shibling;
    int left_child;
    tree(){
        parent         = -1;
        right_shibling = -1;
        left_child     = -1;
    }
};


int find_root(const vector<tree>& T){
    for (int i = 0; i < T.size(); i++) {
        if (T[i].parent == -1) {
            return i;
        }
    }
}

void calc_depth(int id, vector<int>& D, vector<tree>& T) {
    int dep_from_known = 0;
    int known_id;
    for (known_id = id; D[known_id] == -1; known_id = T[known_id].parent) {
        dep_from_known++;
    }
    int dep = D[known_id] + dep_from_known;
    for (int j = id; D[j] == -1; j = T[j].parent) {
        D[j] = dep--;
    }
}

int main(){
    int n;
    cin >> n;
    vector<tree> T(n);
    vector<int> D(n, -1);
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        int k;
        cin >> k;
        if (k > 0) {
            cin >> T[id].left_child;
            int child = T[id].left_child;
            T[child].parent = id;
            for (int j = 1; j < k; j++) {
                cin >> T[child].right_shibling;
                child = T[child].right_shibling;
                T[child].parent = id;
            }
        }
    }
    int root = find_root(T);
    D[root] = 0;
    for (int i = 0; i < n; i++) {
        calc_depth(i, D, T);
        cout << "node " << i << ": parent = " << T[i].parent;
        cout << ", depth = " << D[i] << ", ";
        if (D[i] == 0) {
            cout << "root";
        } else if (T[i].left_child != -1) {
            cout << "internal node";
        } else {
            cout << "leaf";
        }
        cout << ", [";
        for (int child = T[i].left_child; child != -1; child = T[child].right_shibling) {
            cout << child;
            if (T[child].right_shibling != -1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}