#include<iostream>
#include<cstdio>
#include<cstring>
#define Nil -1
#define maxn 100005
using namespace std;
int n,root;
int dep[maxn]; 

struct node
{
    int parent;
    int left_son;
    int right_brother;
    node():parent(Nil),left_son(Nil),right_brother(Nil) {}
};
node t[maxn];

void build()
{
    for(int i=0; i<n; ++i)
    {
        int num,ns,l;
        scanf("%d%d",&num,&ns);
        for(int j=0; j<ns; ++j)									//?????????????????¨??????
        {
            int son;
            scanf("%d",&son);
            if(j==0) t[num].left_son=son;
            else t[l].right_brother=son;
            l=son;
            t[son].parent=num;
        }
    }
    return ;
}

int find_root()
{
    int x;
    for(int i=0; i<n; ++i)
        if(t[i].parent==Nil)
        {
            x=i;
            break;
        }
    return x;
}

void rec(int num,int d)
{
    dep[num]=d;
    if(t[num].right_brother!=Nil) rec(t[num].right_brother,d);
    if(t[num].left_son!=Nil) rec(t[num].left_son,d+1);
    return ;
}

void print(int num)
{
	printf("node %d: ",num);
	printf("parent = %d, ",t[num].parent);
	printf("depth = %d, ",dep[num]);
	if(t[num].parent==Nil) printf("root, [");
	else if(t[num].left_son==Nil) printf("leaf, [");
	else printf("internal node, [");
	for(int i=0,c=t[num].left_son;c!=Nil;i++,c=t[c].right_brother)
	{
		if(i) printf(", ");
		printf("%d",c); 
	}
	printf("]\n");
}

int main()
{
    scanf("%d",&n);
    build();
    root=find_root();
    rec(root,0);
    for(int i=0; i<n; ++i)
        print(i);
    return 0;
}