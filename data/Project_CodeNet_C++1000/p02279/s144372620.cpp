#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=100000+10;
int n;

typedef struct
{
    int parent;
    vector<int> child;

}Node;
Node node[maxn];
int deep[maxn];
void update_deep(int i)
{

    if(node[i].child.empty()) return;
     for(vector<int>::iterator iter=node[i].child.begin();iter!=node[i].child.end();iter++)
     {
         int d=*iter;
         deep[d]=deep[i]+1;
         update_deep(*iter);
     }
}
int main()
{
//    freopen("in.txt","r",stdin);
    memset(deep,0,sizeof(deep));
    int id,du;
    scanf("%d",&n);
    for(int i=0;i<n;i++) node[i].parent=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&id,&du);
        for(int j=0;j<du;j++)
        {
            int d;
            scanf("%d",&d);
            node[d].parent=id;
            node[id].child.push_back(d);
        }
        update_deep(id);
    }
    for(int i=0;i<n;i++)
    {
        printf("node %d: parent = %d, depth = %d, ",i,node[i].parent,deep[i]);
        int len=node[i].child.size();
        if(node[i].parent==-1) printf("root");
        else if(len==0) printf("leaf");
        else printf("internal node");
        printf(", ");
        //sort(node[i].child.begin(),node[i].child.end());
        printf("[");
        for(vector<int>::iterator iter=node[i].child.begin();iter!=node[i].child.end();iter++)
        {
            if(iter!=node[i].child.begin())
            {
                printf(", ");

            }
             printf("%d",*iter);
        }
        printf("]\n");
    }

    return 0;
}