#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 100000
#define NMAX 20

struct Node{
    int n_node;
    int parent;
    int depth;
    vector<int> child;
};

Node N[MAX];

void addDepth(int id, int depth){
    N[id].depth = depth;
    for(int i = 0; i < N[id].child.size(); i++){
        addDepth(N[id].child[i], depth+1);
    }
}

int main(void){
    int n, root;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        N[i].parent = -1;
        N[i].depth = 0;
    }
    
    for(int i = 0; i < n; i++){
        int id, num;
        cin >> id >> num;
        
        N[id].n_node = id;
        for(int j = 0; j < num; j++){
            int id_c;
            
            cin >> id_c;
            N[id_c].parent = N[id].n_node;
            N[id_c].depth = N[id].depth + 1;
            
            N[id].child.push_back(id_c);
        }
    }
    
    root = n;
    for(int i = 0; i < n; i++){
        if(N[i].parent == -1){
            root = N[i].n_node;
            break;
        }
    }
    addDepth(root, 0);
    
    for(int i = 0; i < n; i++){
        cout << "node " << N[i].n_node << ": parent = " << N[i].parent << ", depth = " << N[i].depth << ", ";
        if(N[i].parent >= 0){
            if(N[i].child.size() > 0) cout << "internal node";
            else cout << "leaf";
        }
        else cout << "root";
        cout << ", [";
        for(int j = 0; j < N[i].child.size(); j++){
            if(j) cout << ", ";
            cout << N[i].child[j];
        }
        cout << "]" << endl;
    }
    
    return 0;
}

