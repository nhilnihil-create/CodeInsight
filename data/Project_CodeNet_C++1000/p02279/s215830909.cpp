#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+7;
#define NIL -1
struct Node
{
    int parent,left,right;
}tree[maxn];
int n,Depth[maxn];
void init()
{
    for(int i=0;i<n;i++)tree[i].parent=tree[i].left=tree[i].right=NIL;
}
void calc_depth(int root,int depth)
{
    Depth[root]=depth;
    if(tree[root].right!=NIL)calc_depth(tree[root].right,depth);
    if(tree[root].left!=NIL)calc_depth(tree[root].left,depth+1);
}
void print(int node)
{
    printf("node %d: parent = %d, depth = %d, ",node,tree[node].parent,Depth[node]);
    if(tree[node].parent==NIL)printf("root, ");
    else if(tree[node].left==NIL)printf("leaf, ");
    else printf("internal node, ");
    putchar('[');
    for(int i=0,tmp=tree[node].left;tmp!=NIL;i++,tmp=tree[tmp].right)
    {
        if(i)printf(", ");
        printf("%d",tmp);
    }
    printf("]\n");
}
int main()
{
    cin>>n;
    init();
    for(int i=0;i<n;i++)
    {
        int node_index,a,bro;
        scanf("%d%d",&node_index,&a);
        for(int j=0;j<a;j++)
        {
            int node;
            scanf("%d",&node);
            if(j==0) tree[node_index].left=node;
            else tree[bro].right=node;
            bro=node;
            tree[node].parent=node_index;
        }
    }
    int root;
    for(int i=0;i<n;i++)if(tree[i].parent==NIL)root=i;
    calc_depth(root,0);
    for(int i=0;i<n;i++)print(i);
}
