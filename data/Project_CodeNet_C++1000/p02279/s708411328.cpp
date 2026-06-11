#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
struct Input{
        int degree;
        vector <int> children;
};
struct Tree{
        int parent;
        int depth;
        string type;
};
int N;
map <int,Input> info;
map <int,int> dp;
map <int,Tree> tree;
string Get_type(int now,int degree){
        if(tree[now].parent==-1)
                return "root";
        else if(degree!=0)
                return "internal node";
        else
                return "leaf";
}
void recursion(int now,int depth){
        tree[now].depth=depth;
        for(int i=0 ; i<info[now].degree ; i++ )
                recursion(info[now].children[i],depth+1);
        return;
}
int main(){
        cin >> N;
        for(int i=0 ; i<N ; i++ )
                tree[i].parent=-1;
        for(int i=0 ; i<N ; i++ ){
                int node;
                cin >> node;
                cin >> info[node].degree;
                for(int j=0; j<info[node].degree;j++){
                        int tmp;
                        cin >> tmp;
                        info[node].children.push_back(tmp);
                        tree[tmp].parent=node;
                }
                dp[i]=-2;
        }
        int s;
        for(int i=0 ; i<N ; i++ )
                if(tree[i].parent==-1){
                        s=i;
                        break;
                }
        recursion(s,0);
        for(int i=0 ; i<N ; i++ ){
                cout<<"node "<<i<<": parent = "<<tree[i].parent;
                cout<<", depth = "<<tree[i].depth<<", ";
                cout<<Get_type(i,info[i].degree)<<", [";
                for(int j=0 ; j<info[i].degree ; j++ ){
                        cout<<info[i].children[j];
                        if(j!=info[i].degree-1)
                                cout<<", ";
                }
                cout<<"]"<<endl;
        }
        return 0;
}
