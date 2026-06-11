#include <iostream>
#include <cstring>
using namespace std;
struct Node {
	int sib;
	int par;
	int chi;
	int dep;
};

Node N[100000] = {-1};

int root;

void print(int id)
{	
	Node cur=N[id];
		cout<< "node " <<id<<": parent = "<<cur.par;
		cout<<", depth = "<<cur.dep;
		if (id==root) cout<<", root, [";
		else if (cur.chi==-1) {cout<<", leaf, []"<<endl;return;}
		else cout<<", internal node, [";
		int chi=cur.chi;
		while(chi!=-1){
			cout << chi;
			chi = N[chi].sib;
			if (chi==-1)break;
			cout<<", ";
		}
		cout<<']'<<endl;
}

int main()
{
	memset(N,-1,sizeof(N));
	int n, id,c,chi,sib;
	cin >>n;
	for(int i=0;i<n;i++){
		cin>>id>>c;
		for(int j=0;j<c;j++)
		{
			cin>>chi;
			if (j==0) N[id].chi=chi;
			else N[sib].sib = chi;
			N[chi].par=id;
			sib=chi;
		}
	}
	
	for (int i=0;i<100000;i++)
	{
		if ((N[i].chi!=-1) && (N[i].par==-1))
		{
			root = i;
		}
	}
	
	id=root;
	int d=0;
	while(1)
	{
		Node &cur = N[id];
		cur.dep =d;
		if (cur.chi!=-1){id = cur.chi;d++;}
		else if (cur.sib!=-1)id=cur.sib;
		else {
			while(1)
			{
				if (d==0) break;
				d--;
				id = N[id].par;
				if (N[id].sib!=-1) 
				{
					id = N[id].sib;
					break;
				}
			}
		}
		if(d==0)break;
	}
	
	for (int i=0;i<100000;i++)
	{
		if (N[i].dep!=-1)
		{
			print(i);
		}
	}
	
	return 0;
}