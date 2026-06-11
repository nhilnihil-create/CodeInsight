#include <iostream>
using namespace std;
#define MAX 100005
#define NIL -1

//?????????????????¨??????
//left-child right-sibling representation
struct node{
    int parent;
    int left;
    int right;
};

node T[MAX];
int depth[MAX];
int n;

void print(int u){
    cout<<"node "<<u<<": ";
    cout<<"parent = "<<T[u].parent<<", ";
    cout<<"depth = "<<depth[u]<<", ";

    if(T[u].parent == NIL)
        cout<<"root, ";
    else if(T[u].left == NIL)
        cout<<"leaf, ";
    else
        cout<<"internal node, ";

    cout<<"[";

    for(int i=0,c=T[u].left;c!=NIL;i++,c=T[c].right){
        if(i)
            cout<<", ";
        cout<<c;
    }
    cout<<"]"<<endl;
}

// ????????°?±???±???
void rec(int u,int p){
    depth[u]=p;
    //?????§???????????????????????±???
    if(T[u].right!=NIL)
        rec(T[u].right,p);
    //????????§??????????????±?????????????????±?????±???+1
    if(T[u].left!=NIL)
        rec(T[u].left,p+1);
}

int main(){
    int degree;
    int nodeID;
    int childNode;
    int lastChildNode;
    int root;
    cin>>n;
    for(int i=0;i<n;i++)
        T[i].parent=T[i].left=T[i].right=NIL;
    for(int i=0;i<n;i++){
        cin>>nodeID>>degree;
        for(int j=0;j<degree;j++){
            cin>>childNode;
            if(j==0)
                T[nodeID].left=childNode;
            else
                T[lastChildNode].right=childNode;
            lastChildNode=childNode;
            T[childNode].parent=nodeID;
        }
    }
    //?????°?????????
    for(int i=0;i<n;i++)
        if(T[i].parent==NIL)
            root=i;
    //????????±???
    rec(root,0);
    //print
    for(int i=0;i<n;i++)
        print(i);
}