#include<vector>
#include<cstdio>
class Tree{
private:
    int numVertex;
    int *parent, *depth;
    std::vector<int> *child;
public:
    Tree(int v);
    ~Tree();
    void addEdge(int p,int c);
    void printData();
    void printData(int v);
    bool isRoot(int v);
    void computeDepth(int v);
    void computeDepth();
};
Tree::Tree(int v){
    numVertex=v;
    parent=new int[v];
    for(int i=0;i<v;i++)parent[i]=-1;
    depth=new int[v];
    for(int i=0;i<v;i++)depth[i]=-1;
    child=new std::vector<int>[v];
}
Tree::~Tree(){
    delete[] parent;
    delete[] child;
}
void Tree::addEdge(int p,int c){
    parent[c]=p;
    child[p].push_back(c);
}
bool Tree::isRoot(int v){
    return parent[v]==-1;
}
void Tree::computeDepth(){
    for(int i=0;i<numVertex;i++){
        if(isRoot(i))computeDepth(i);
    }
}
void Tree::computeDepth(int v){
    if(isRoot(v))depth[v]=0;
    for(auto itr=child[v].begin();itr!=child[v].end();itr++){
        depth[*itr]=depth[v]+1;
        computeDepth(*itr);
    }
}
void Tree::printData(int v){
    printf("node %d: ",v);
    printf("parent = %d, ",parent[v]);
    printf("depth = %d, ",depth[v]);
    if(parent[v]==-1)printf("root, ");
    else if(child[v].empty())printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    for(auto itr=child[v].begin(); itr!=child[v].end(); itr++){
        printf("%s%d",(itr==child[v].begin())?"":", ",*itr);
    }
    printf("]\n");
}
void Tree::printData(){
    for(int i=0;i<numVertex;i++)printData(i);
}
int main(){
    int n;
    scanf("%d",&n);
    Tree t(n);
    for(int i=0;i<n;i++){
        int id,k;
        scanf("%d%d",&id,&k);
        for(int j=0;j<k;j++){
            int c;
            scanf("%d",&c);
            t.addEdge(id,c);
        }
    }
    t.computeDepth();
    t.printData();
    return 0;
}
