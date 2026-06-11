#include <iostream>
using namespace std;

struct Node
{
	int Parent;
	int RightSibling;
	int LeftChild;
	int Depth;
	
	Node()
	{
	    Parent = -1;
	    RightSibling = -1;
	    LeftChild = -1;
	    Depth = -1;
	}
};

Node tree[100007];

void Run(int N)
{
	int t = tree[N].LeftChild;
	
	while(t != -1)
	{		
		tree[t].Depth = tree[N].Depth + 1;
		Run(t);
		t = tree[t].RightSibling;
	}
}

int main()
{
	int N, ID, K, C;
	cin >> N;
	
	for(int i = 0; i < N; ++i)
	{
		tree[i] = Node();
	}
	
	for(int i = 0; i < N; ++i)
	{
		cin >> ID >> K;
		for(int j = 0, child; j < K; ++j)
		{
			cin >> C;
						
			if(j == 0)
			{
				tree[ID].LeftChild = C;		
			}
			else
			{
				tree[child].RightSibling = C;
			}
			
			tree[C].Parent = ID;
			child = C;
		}
	}
	
	for(int i = 0; i < N; ++i)
	{
		if(tree[i].Parent == -1)
		{
			tree[i].Depth = 0;
			Run(i);
		}
	}
	
	for(int i = 0; i < N; ++i)
	{
		cout << "node " << i << ": parent = " << tree[i].Parent << ", depth = " << tree[i].Depth << ", ";
		
		if(tree[i].Parent == -1)
		{
			cout << "root";
		}
		else if(tree[i].LeftChild == -1)
		{
			cout << "leaf";
		}
		else
		{
			cout << "internal node";
		}
		
		cout << ", [";
		int t = tree[i].LeftChild;
		bool is_first = true;
		while(t != -1)
		{
			if(!is_first)
			{
				cout << ", ";
			}
			
			cout << t;
			t = tree[t].RightSibling;
			is_first = false;
		}
		cout << "]" << endl;
	}

    return 0;
}

