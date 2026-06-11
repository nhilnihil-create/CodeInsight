#include<iostream>
#include<vector>
using namespace std;
struct Node {
    int parent = -2;
    string type;
    vector<int> children;
};
int main() {
    int n;
    cin >> n;
    Node node[n];
    for (int i = 0; i < n; i++) {
        int id, k;
        cin >> id >> k;
        if (k == 0) { //no children
            node[id].type = "leaf";
        }
        if (node[id].parent == -2) {
            node[id].parent = -1;
        }
        int cnt3 = 0;
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            node[c].parent = id;
            node[id].children.push_back(c);
            cnt3++;
        }
        node[id].children.push_back(-2);
    }
    for (int i = 0; i < n; i++) {
        cout << "node " << i << ": parent = " << node[i].parent;
        cout << ", depth = ";
        int tmp = i;
        int cnt = 0;
        while (node[tmp].parent != -1) {
            tmp = node[tmp].parent;
            cnt++;
        }
        cout << cnt << ", ";
        if (node[i].parent == -1) {
            cout << "root";
        } else if (node[i].type == "leaf") {
            cout << "leaf";
        } else {
            cout << "internal node";
        }
        cout << ", [";
        int cnt2 = 0;
        while (1) {
            if (node[i].children[cnt2] == -2) { //最初に置かな最初の-2見逃す
                break;
            }
            if (cnt2) {
                cout << ", ";
            }
            cout << node[i].children[cnt2];
            cnt2++;
        }
        cout << "]" << endl;
    }
    return 0;
}


