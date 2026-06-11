#include<cstdio>
#include<cstdlib>

struct Node{
	int key;
	Node *parent, *left, *right;
};

Node *root, *NIL;

void insert(int k)
{
	Node *y = NIL;
	Node *x = root;
	Node *z = (Node *)malloc(sizeof(Node));
	z->key = k;

	while(x != NIL)
	{
		y = x;
		if(z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if(y == NIL)
		root = z;
	else
	{
		if(z->key < y->key)
			y->left = z;
		else
			y->right = z;
	}
}

bool find(int k)
{
	Node *x = root;
	while(x != NIL)
	{
		if(k < x->key)
			x = x->left;
		else if(k == x->key)
			return true;
		else
			x = x->right;
	}

	return false;
}

void Inorder(Node *u)
{
	if(u == NIL) return;

	Inorder(u->left);
	printf(" %d", u->key);
	Inorder(u->right);
}

void Preorder(Node *u)
{
	if(u == NIL) return;

	printf(" %d", u->key);
	Preorder(u->left);
	Preorder(u->right);
}

int main()
{
	int n;
	char s[10];
	int x;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%s", s);
		if(s[0] == 'i')
		{
			scanf("%d", &x);
			insert(x);
		}
		else if(s[0] == 'p')
		{
			Inorder(root);
			printf("\n");
			Preorder(root);
			printf("\n");
		}
		else{
			scanf("%d", &x);
			if(find(x))
				printf("yes\n");
			else
				printf("no\n");
		}
	}

	return 0;

}
