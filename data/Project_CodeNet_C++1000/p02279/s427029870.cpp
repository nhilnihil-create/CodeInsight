#include<cstdlib>
#include<vector>

class RootedTree{
private:
    static const int NIL = -1;
    struct Node{
        // left: child, right: sibling
        int parent, left, right, depth;
        Node(){parent = left = right = depth = NIL;}
    };
    std::vector<Node> T;
    int root;
public:
    RootedTree(int N):T(N){root = NIL;}
    void addNode(int p, int c){
        static int sib;
        if(T[p].left == NIL) T[p].left = c;
        else T[sib].right = c;
        T[c].parent = p;
        sib = c;
    }
    void makeTree(){
        setRoot();
        setDepth(root, 0);
    }
    int getDepth(int v){
        return T[v].depth;
    }
    int getParent(int v){
        return T[v].parent;
    }
    std::vector<int> getChildren(int v){
        std::vector<int> c;
        for(int i=T[v].left;i!=NIL;i=T[i].right) c.push_back(i);
        return c;
    }
    int getType(int v){
        if(T[v].parent == NIL) return NIL;
        if(T[v].left == NIL) return 1;
        else return 0;
    }
private:
    void setRoot(){
        for(size_t i=0;i<T.size();++i)
            if(T[i].parent == NIL) root = i;
    }
    void setDepth(int v, int d){
        T[v].depth = d;
        if(T[v].right != NIL) setDepth(T[v].right, d);
        if(T[v].left != NIL) setDepth(T[v].left, d+1);
    }
};
#include<iostream>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    RootedTree T(n);
    for(int i=0;i<n;++i){
        int id, k;
        cin>>id>>k;
        for(int j=0;j<k;++j){
            int c;
            cin>>c;
            T.addNode(id, c);
        }
    }
    T.makeTree();
    for(int i=0;i<n;++i){
        cout<<"node "<<i<<": parent = "<<T.getParent(i)<<", depth = "<<T.getDepth(i)<<", "<<(T.getType(i)?~T.getType(i)?"leaf":"root":"internal node")<<", [";
        vector<int> c = T.getChildren(i);
        for(size_t j=0;j<c.size();++j)
            if(!j) cout<<c[j];
            else cout<<", "<<c[j];
        cout<<"]"<<endl;
    }
}