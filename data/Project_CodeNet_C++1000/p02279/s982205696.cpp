#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>

#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define var auto
#define mod 1000000007
#define inf 2147483647
#define nil -1
typedef long long ll;

using namespace std;

int inputValue(){
    int a;
    cin >> a;
    return a;
}

template <typename T>
void output(T a, int precision) {
    if(precision > 0){
        cout << fixed << setprecision(precision)  << a << "\n";
    }
    else{
        cout << a << "\n";
    }
}

// end of template
struct node {
    int parent; // parent
    int left; // left child
    int right; // right sibling
    int depth; // root: 0
    void init(){
        parent = nil;
        left = nil;
        right = nil;
        depth = nil;
    }
};

vector<node> nd;

void calcDepth(int parent, int cd){ // parent index, node, current depth
    nd[parent].depth = cd;
    if (nd[parent].right != nil) {
        calcDepth(nd[parent].right, cd);
    }
    if (nd[parent].left != nil) {
        calcDepth(nd[parent].left, cd + 1);
    }
}

void print(int ind){
    cout << "node " << ind << ": ";
    cout << "parent = " << nd[ind].parent << ", ";
    cout << "depth = " << nd[ind].depth << ", ";
    if (nd[ind].parent == nil) {
        cout << "root";
    }
    else if(nd[ind].left == nil){
        cout << "leaf";
    }
    else{
        cout << "internal node";
    }
    cout << ", [";
    vector<int> child;
    if (nd[ind].left != nil) {
        child.push_back(nd[ind].left);
        int l = nd[ind].left;
        while (nd[l].right != nil) {
            child.push_back(nd[l].right);
            l = nd[l].right;
        }
    }
    rep(i, child.size()){
        if (i) cout << ", ";
        cout << child[i];
    }
    cout << "]" << endl;
}



int main() {
    // source code
    int N = inputValue();
    nd.resize(N);
    rep(i, N){
        nd[i].init();
    }
    rep(i, N){
        int ind = inputValue();
        int childnum = inputValue();
        vector<int> child(childnum);
        rep(j, childnum){
            child[j] = inputValue();
        }
        rep(j, childnum){
            if (j == 0) {
                nd[ind].left = child[j];
            }
            else{
                nd[child[j - 1]].right = child[j];
            }
            nd[child[j]].parent = ind;
        }
    }
    // set root
    int root = -1;
    rep(i, N){
        if (nd[i].parent == nil) {
            root = i;
        }
    }
    
    calcDepth(root, 0);
    
    rep(i, N){
        print(i);
    }
    
    return 0;
}