#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int n;

struct node
{
	int id, k, d, pid;
	int* cid;
	string type;
}N[100005];

void GetDepth(node& GN)
{
	GN.d = 0;
	node temp = GN;

	while (temp.pid != -1)
	{
		GN.d++;
		temp = N[temp.pid];
	}
}

void GetType(node& GN)
{
	if (GN.pid == -1)
		GN.type = "root";
	else if (GN.k == 0)
		GN.type = "leaf";
	else
		GN.type = "internal node";
}

void print()
{
	for (int i = 0; i < n; i++)
	{
		cout << "node " << N[i].id << ": " << "parent = " << N[i].pid << ", " << "depth = " << N[i].d << ", " << N[i].type << ", " << "[";

		if (N[i].k != 0)
		{
			for (int j = 0; j < N[i].k - 1; j++)
				cout << N[i].cid[j] << ", ";
			cout << N[i].cid[N[i].k - 1];
		}

		cout << "]" << endl;
	}	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int place;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		N[i].pid = -1;
	
	for (int i = 0; i < n; i++)
	{
		cin >> place;
		N[place].id = place;
		cin >> N[place].k;

		if (N[place].k > 0)
			N[place].cid = (int*)malloc(sizeof(int) * N[place].k);

		for (int j = 0; j < N[place].k; j++)
		{
			cin >> N[place].cid[j];
			for (int t = 0; t < n; t++)
			{
				if (N[place].cid[j] == t)
				{
					N[t].pid = N[place].id;
					break;
				}	
			}
		}			
	}

	for (int i = 0; i < n; i++)
		GetDepth(N[i]);

	for (int i = 0; i < n; i++)
		GetType(N[i]);	

	print();

	return 0;
}
