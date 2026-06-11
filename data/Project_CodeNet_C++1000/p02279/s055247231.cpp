#include <iostream>
#include <vector>

using namespace std;

struct Tree {
    int node;
    int parent;
    int leftChild;
    int rightBrother;
    int depth;
    string kind;
    vector<int> children;
};

#define tree struct Tree

int n;
tree t[100000];

void calculateDepth();
void decideKind();
void calculate(int id);
void findChildren();

int main(){
    cin>>n;
    for (int i=0; i<n; i++) {
        t[i].parent = -3; //-3 null
    }
    for (int i=0; i<n; i++) {
        int id;
        cin>>id;
        t[id].node = id;
//        if (i==0) {
//            t[id].parent = -1;
//        }
        int k;
        cin>>k;
        if (k == 0) {
            t[id].leftChild = -2;
        }
        else if (k != 0) {
            int left_child;
            cin>>left_child;
            t[left_child].parent = id;
            t[id].leftChild = left_child;
            int a,b;
            a = left_child;
            if ( k > 1){
                for (int j=0; j<k-1; j++) {
                    cin>>b;
                    t[a].rightBrother = b;
                    t[a].parent = id;
                    a=b;
                }
                t[b].parent = id;
                t[b].rightBrother = -2; //-2 : null
            }else if (k==1){
                t[a].parent = id;
                t[a].rightBrother = -2;
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (t[i].parent == -3) {
            t[i].parent = -1;
        }
    }
    
    //calculate depth
    calculateDepth();
    
    //decide kind
    decideKind();
    
    //find children
    findChildren();
    
    //output
    for (int i=0; i<n; i++) {
        cout<<"node "<<i<<": parent = "<<t[i].parent<<", depth = "<<t[i].depth<<", "<<t[i].kind<<", [";
        if (!t[i].children.empty()) {
            for (int j=0; j<t[i].children.size()-1; j++) {
                cout<<t[i].children[j]<<", ";
            }
            cout<<t[i].children[t[i].children.size()-1];
        }
        cout<<"]"<<endl;
    }
}

void calculateDepth(){
    //find root
    int rootId;
    int root_id;
    for (int rootId=0; rootId<n; ++rootId) {
        if (t[rootId].parent == -1) {
            root_id = rootId;
            t[rootId].depth = 0;
            break;
        }
    }
    calculate(t[root_id].leftChild);
    return;
}

void calculate(int id){
    if (id >= 0) {
        //cout<<t[t[id].parent].depth<<endl;
        t[id].depth = t[t[id].parent].depth + 1;
        calculate(t[id].leftChild);
        calculate(t[id].rightBrother);
    }
}

void decideKind(){
    for (int i=0; i<n; i++) {
        if (t[i].parent == -1) {
            t[i].kind = "root";
        }
        else if(t[i].leftChild == -2){
            t[i].kind = "leaf";
        }
        else{
            t[i].kind = "internal node";
        }
    }
}

void findChildren(){
    for (int i=0; i<n; i++) {
        if (t[i].leftChild != -2) {
            tree tmp;
            tmp = t[t[i].leftChild];
            while (tmp.rightBrother != -2) {
                t[i].children.push_back(tmp.node);
                tmp = t[tmp.rightBrother];
            }
            t[i].children.push_back(tmp.node);
        }
    }
}