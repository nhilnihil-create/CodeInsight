#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct Tree{
        int left;int right;
};
map <int,Tree> tree;
int N;
int recursion(int now,int way){
        if(way==0)
                cout<<" "<<now;
        if(tree[now].left!=-1)
                recursion(tree[now].left,way);
        if(way==1)
                cout<<" "<<now;
        if(tree[now].right!=-1)
                recursion(tree[now].right,way);
        if(way==2)
                cout<<" "<<now;
}
int main(){
        cin >>N;
        vector <bool> child(N,0);
        for(int i=0 ; i<N ; i++ ){
                int node;
                cin >> node;
                cin >> tree[node].left >> tree[node].right;
                if(tree[node].left!=-1)
                        child[tree[node].left]=1;
                if(tree[node].right!=-1)
                        child[tree[node].right]=1;
        }int root;
        for(int i=0 ; i<N ; i++ )
                if(!child[i]){
                        root=i;
                        break;
                }
        cout<<"Preorder"<<endl;
        recursion(root,0);
        cout<<endl<<"Inorder"<<endl;
        recursion(root,1);
        cout<<endl<<"Postorder"<<endl;
        recursion(root,2);
        cout<<endl;
        return 0;
}
