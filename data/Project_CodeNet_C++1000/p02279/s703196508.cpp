#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define For(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define ALL(v) v.begin(), v.end()

const int NOT_DEFINED = -111;

class Tree {
    int n;
    vector<vector<int>> adjlist;
    vector<vector<int>> inv_adjlist;
    vector<int> depthList;

public:
    Tree(int num);
    int getParent(int id);
    void addNode(int parentId, int childId);
    int getDepth(int id);
    string getType(int id);
    vector<int> getChild(int id);
};

Tree::Tree(int num) {
    n = num;
    REP(i,num) {
        vector<int> v;
        adjlist.push_back(v);
        inv_adjlist.push_back(v);
        depthList.push_back(NOT_DEFINED);
    }
}

void Tree::addNode(int parentId, int childId) {
    adjlist[parentId].push_back(childId);
    inv_adjlist[childId].push_back(parentId);
}

int Tree::getParent(int id) {
    vector<int> parent = inv_adjlist[id];
    if (parent.size()) return parent[0];
    return -1;
}

int Tree::getDepth(int id) {
    //if (depthList[id] != NOT_DEFINED) return depthList[id];
    int depth = 0;
    vector<int> parent = inv_adjlist[id];
    while(parent.size()) {
        if (depthList[parent[0]] != NOT_DEFINED) {
            depth += depthList[parent[0]] + 1;
            break;
        }
        parent = inv_adjlist[parent[0]];
        depth++;
    }
    
    /* slow code
    int parent = id;
    while (1) {
        parent = getParent(parent);
        if (parent != -1) {
            depth++;
        }else {
            break;
        }
    }*/
    depthList[id] = depth;
    return depth;
}

string Tree::getType(int id) {
    if (depthList[id] == 0) {
        return "root";
    }else if (adjlist[id].empty()) {
        return "leaf";
    }else {
        return "internal node";
    }
    return "";
}

vector<int> Tree::getChild(int id) {
    return adjlist[id];
}

int main() {
    int n;
    cin >> n;
    Tree tree = Tree(n);
    REP(i,n) {
        int id, deg;
        cin >> id >> deg;
        int k;
        REP(j,deg) {
            cin >> k;
            tree.addNode(id, k);
        }
    }
    
    REP(i,n) {
        vector<int> children = tree.getChild(i);
        cout << "node " << i << ": parent = ";
        cout << tree.getParent(i) << ", depth = ";
        cout << tree.getDepth(i) << ", ";
        cout << tree.getType(i) << ", [";
        REP(j,children.size()) {
            cout << children[j];
            if (j < children.size()-1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}