#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn=100005;
struct tree
{
    int parent;
    vector<int>child;
    int depth;
};
tree node[maxn];
int n;
void init()
{
    for (int i=0;i<n;i++)
        node[i].depth=node[i].parent=-1;
}
int Find (int x)
{
    if(node[x].parent==-1)
        return node[x].depth=0;
    else if(node[x].depth!=-1)
        return node[x].depth;
    else
        return Find(node[x].parent)+1;
}
int main()
{
    scanf("%d",&n);
    init();
    for (int i=0;i<n;i++)
    {
        int x,num;
        scanf("%d%d",&x,&num);
        while (num--)
        {
            int y;
            scanf("%d",&y);
            node[y].parent=x;
            node[x].child.push_back(y);
        }
    }
    for (int i=0;i<n;i++)
    {
        printf("node %d: parent = %d, depth = %d, ",i,node[i].parent,node[i].depth=Find(i));
        if(node[i].parent==-1)
            printf("root, ");
        else if(!node[i].child.size())
            printf("leaf, ");
        else
            printf("internal node, ");
        printf("[");
        for (int j=0;j<node[i].child.size();j++)
        {
            printf("%d",node[i].child[j]);
            if(j<node[i].child.size()-1)
                printf(", ");
        }
        printf("]\n");
    }
    return 0;
}

