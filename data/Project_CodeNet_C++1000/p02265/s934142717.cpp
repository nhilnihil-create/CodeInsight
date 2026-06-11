#include<cstdio>
#include<cstdlib>
#include<cstring>

typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node{
	int num;
	Position Next;
	Position Before;
};

void Insert(List L,int e)
{
	Position Current;
	Current=(Position)malloc(sizeof(struct Node));
	Current->num=e;
	if(L->Next==L)
	{
		Current->Next=L;
		Current->Before=L;
		L->Before=Current;
		L->Next=Current;
	}
	else
	{
		Current->Next=L->Next;
		Current->Before=L;
		L->Next->Before=Current;
		L->Next=Current;
	}
}

void Delete(List L,int x)
{
	Position TmpCell=L;
	while((TmpCell->Next)!=L)
	{
		Position Current=TmpCell->Next;
		if((Current->num)==x)
		{
			TmpCell->Next=Current->Next;
			Current->Next->Before=TmpCell;
			break;
		}
		TmpCell=Current;
	}
}

void deleteFirst(List L)
{
	if(L->Next!=L)
	{
		Position Current=L->Next;
		L->Next=Current->Next;
		Current->Next->Before=L;
	}
}

void deleteLast(List L)
{
	L->Before->Before->Next=L;
	L->Before=L->Before->Before;
}

void printList(List L)
{
	Position TmpCell=L;
	while(TmpCell->Next!=L)
	{
		Position Current=TmpCell->Next;
		printf("%d",Current->num);
		if(Current->Next!=L)
			printf(" ");
		TmpCell=Current;
	}
	printf("\n");
}
int main()
{
	int n;
	scanf("%d",&n);
	char op[15];
	int e;
	List L=(Position)malloc(sizeof(struct Node));
	L->num=-1;
	L->Next=L;
	L->Before=L;
	for(int i=0;i<n;i++)
	{
		scanf("%s",op);
		if(strcmp(op,"insert")==0)
		{
			scanf("%d",&e);
			Insert(L,e);
		}
		else if(strcmp(op,"delete")==0)
		{
			scanf("%d",&e);
			Delete(L,e);
		}
		else if(strcmp(op,"deleteFirst")==0)deleteFirst(L);
		else if(strcmp(op,"deleteLast")==0)deleteLast(L);
	}
	printList(L);
	return 0;
}