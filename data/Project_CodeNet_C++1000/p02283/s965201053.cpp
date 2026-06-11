#define _CRT_SECURE_NO_WARNINGS
#include <iostream>  
#include <stdlib.h> 
#include <stdio.h>  
#include <string>
#include <string.h>
#include <math.h>  
#include <time.h>
#include <list>
#include <map>  
#include <queue>  
#include <set>
#include <stack>
#include <vector>  
#include <algorithm>
#define ms(a) memset(a,0,sizeof(a)) 
#define inf 0x3f3f3f3f
#define MAX 100010
#define MX 10010
#define ll long long
using namespace std;
struct node
{
	int data;
	node *lch,*rch,*par;
}*root,*null;
void insert(int k)
{
	node *cur=root,*res=null,*ins=(node*)malloc(sizeof(node));
	ins->data=k;
	ins->lch=null;
	ins->rch=null;
	while (cur!=null)
	{
		res=cur;
		if(ins->data<cur->data)cur=cur->lch;
		else cur=cur->rch;
	}
	ins->par=res;//定?父?点
	if(res==null)root=ins;//第一次插入
	else{//定?左右子
		if(ins->data<res->data)res->lch=ins;
		else res->rch=ins;
	}
}
void inorder(node *cur)
{
	if(cur==null)return;
	inorder(cur->lch);
	printf(" %d",cur->data);
	inorder(cur->rch);
}
void preorder(node *cur)
{
	if(cur==null)return;
	printf(" %d",cur->data);
	preorder(cur->lch);
	preorder(cur->rch);
}
int main()
{
	int n,m;
	char oper[10];
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s",&oper);
		if(oper[0]=='i'){
			scanf("%d",&m);
			insert(m);
		}
		else if(oper[0]=='p'){
			inorder(root);
			printf("\n");
			preorder(root);
			printf("\n");
		}
	}
	return 0;
}