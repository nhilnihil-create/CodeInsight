#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class Node{
    public:
        int id;
        int parent;
        int depth;
        int degree;
        int sibling;
        int high;
        string type;
        Node* right;
        Node*  left;
        Node():id(-1),parent(-1),depth(-1),degree(0),sibling(-1),high(0),type(""){}
};

vector<Node> root;

int dfs(int id,int d){

    int h;
    root[id].high=0;
      
    if(root[id].depth<d)
        root[id].depth=d;
    if(root[id].right->id!=-1){
        root[id].right->sibling=root[id]. left->id;
    }
    if(root[id]. left->id!=-1){
        root[id]. left->sibling=root[id].right->id;
    }

    if(root[id].right->id!=-1){
        h=dfs(root[id].right->id,d+1);
    }
    if(root[id].high<h)
        root[id].high=h;

    if(root[id]. left->id!=-1){
        h=dfs(root[id].left->id,d+1);
    }
    if(root[id].high<h)
        root[id].high=h;
    //return h+1;
    return root[id].high+1;
}


void pro(int id){
    if(root[id].id!=-1){
        cout<<" "<<root[id].id;
        if(root[id]. left->id!=-1)
            pro(root[id]. left->id);
        if(root[id].right->id!=-1)
            pro(root[id].right->id);
    }
}

void ino(int id){
    if(root[id].id!=-1){
        if(root[id]. left->id!=-1)
            ino(root[id].left->id);
        cout<<" "<<root[id].id;
        if(root[id].right->id!=-1)
            ino(root[id].right->id);
    }
}


void pos(int id){
    if(root[id].id!=-1){
        if(root[id]. left->id!=-1)
            pos(root[id]. left->id);
        if(root[id].right->id!=-1)
            pos(root[id].right->id);
        cout<<" "<<root[id].id;
    }
}                         




int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int n, l, r;
    cin>>n;
    for(int i=0;i<n;i++){
        Node node;
        cin>>node.id>>l>>r;
        node.left=new Node();
        node.right=new Node();
        node.left->id=l;
        node.right->id=r;
        root.push_back(node);
    }

    sort(begin(root),end(root),
            [](const Node &r, const Node &l){
            return r.id < l.id;
    });

   for(int i=0; i<n; i++){
        root[root[i].right->id].parent=root[i].id;
        root[root[i].left->id].parent=root[i].id;
        /*親をセット*/
   }
   for(int i=0;i<n;i++){
       if(root[i].parent==-1)
            root[i].high=dfs(i,0);
       if(root[i]. left->id!=-1){
            root[i].degree++;
       }
       if(root[i].right->id!=-1){
            root[i].degree++;
       }
   }
   for(int i=0;i<n;i++){
         root[root[i].right->id].sibling=root[root[i]. left->id].id;
         root[root[i]. left->id].sibling=root[root[i].right->id].id;
   }

   int p;
   for(int i=0;i<n;i++){  
         if(root[i].parent==-1){
            p=i;
        }
    }
    cout<<"Preorder"<<endl;
    pro(p);
    cout<<"\nInorder"<<endl;
    ino(p);
    cout<<"\nPostorder"<<endl;
    pos(p);
    cout<<endl;

    for(int i=0;i<root.size();i++){
        delete root[i].right;
        delete root[i].left;
    }
    return 0; 
}