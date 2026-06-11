#include<bits/stdc++.h>
using namespace std;
/*
alias g='g++ -std=c++17 -O2 pra.cpp'
alias a='./a.out'
cd programming
cd cpp
cd practice

*/
#define rep(i, n) for(int (i)=0; (i)<(n); i++)
#define pb push_back
using veci = vector<int>;
using ll = long long;
using G = vector<vector<int>>;
struct Node{
    int id;
    int parent;
    int depth;
    veci children;
    void addChild(int num){
        children.pb(num);
    }
};

using P = pair<Node, int>;

Node tree[100100];
void init(int n){
    rep(i, n){
        tree[i].depth = tree[i].parent = -1;
        tree[i].children.clear();
    }
    return;
}
int main(){
    int n, id, num, childsid;
    cin >> n;
    
    init(n);
    rep(i, n){
        cin >> id >> num;
        tree[id].id = id;
        rep(j, num){
            cin >> childsid;
            tree[id].addChild(childsid);
            tree[childsid].parent = id;
            }
    }
    int root;
    rep(i, n){
        if (tree[i].parent == -1){
            root = i;
            break;
        }
    }
    queue<P> q;
    q.push(make_pair(tree[root], -1));
    while(!q.empty()){
        P p = q.front(); q.pop();
        tree[p.first.id].depth = p.second + 1;
        rep(i, p.first.children.size()){
            q.push(make_pair(tree[p.first.children[i]], p.second+1));
        }
    }

    rep(i, n){
        cout << "node " << i << ": parent = ";
        cout << tree[i].parent << ", depth = ";
        cout << tree[i].depth << ", "; 
        if(tree[i].parent == -1){
            cout << "root";
        }
        else if(tree[i].children.empty())cout << "leaf";
        else cout << "internal node";
        cout << ", [";
        rep(j, tree[i].children.size()){
            cout << tree[i].children[j];
            if (j != tree[i].children.size()-1) cout << ", ";
        }
        cout << "]" << endl;
    }
}
