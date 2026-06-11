#include <iostream>
using namespace std;
const int MAX = 100005;
const int NIL = -1;

struct  Node
{
	int key;
	int depth;
	int pa;
	int left;
	int right;
};

Node Tree[MAX];
void print(int n);
void set_depth(int, int);

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Tree[i].pa = Tree[i].left = Tree[i].right = NIL;
	}

	for (int i = 0; i < n; i++)
	{
		int num, degree;
		cin >> num >> degree;
		for (int j = 0; j < degree; j++)
		{
			int chil, sib;
			cin >> chil;
			
			if (j == 0)
				Tree[num].left = chil;
			else
				Tree[sib].right = chil;
			
			sib = chil;
			Tree[chil].pa = num;
		}
	}

	int root = 0;
	for (int i = 0; i < n; i++)
	{
		if (Tree[i].pa == NIL)
		{
			root = i;
			break;
		}
	}

	set_depth(root, 0);

	for (int i = 0; i < n; i++)
		print(i);

	return 0;
}

void print(int n)
{
	cout << "node " << n << ": parent = " << Tree[n].pa;
	cout << ", depth = " << Tree[n].depth;
	cout << ", ";

	if (Tree[n].pa == NIL)
		cout << "root";
	else if (Tree[n].left == NIL)
		cout << "leaf";
	else
		cout << "internal node";
	cout << ", [";

	int bro = Tree[n].left;
	if (bro != NIL)
	{
		cout << bro;
		int sib = Tree[bro].right;
		while (sib != NIL)
		{
			cout << ", " << sib;
			sib = Tree[sib].right;
		}
	}

	cout << "]" << endl;
	return;
}

void set_depth(int num, int d)
{
	Tree[num].depth = d;
	if (Tree[num].right != NIL)
		set_depth(Tree[num].right, d);
	if (Tree[num].left != NIL)
		set_depth(Tree[num].left, d + 1);
	return;
}