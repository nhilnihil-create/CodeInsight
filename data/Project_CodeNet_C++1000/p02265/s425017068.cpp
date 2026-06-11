#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
using namespace std;
#define len(n) (int)n.length()
#define dump cout
#define pb push_back
#define ll long long

class CL
{
	public:
	CL* prev;
	ll key;
	CL* next;
};

CL* NIL;

void output(CL* li, ll n)
{
	for (ll i = 0; i < n; i++) {
		if (li[i].key == -1)
			break;
	    cout << li[i].key << " ";
	}
	cout << endl;
}

CL* Search(ll key)
{
	CL* cur = NIL->next;
	while((cur != NIL) && (cur->key != key))
	{
		cur = cur->next;
	}
	return cur;
}

int main()
{
	// ios::sync_with_stdio(false);
	
	ll n;
	scanf("%d",&n);

	// init
	NIL = new CL();
	NIL->next = NIL;
	NIL->prev = NIL;
	
	for (ll i = 0; i < n; i++) {
	    char opt[20];
		string op;
		ll key;
		scanf("%s %d", opt, &key);
		op = opt;
		if (op == "insert")
		{
					CL* elem = new CL();
			elem->next = NIL->next;
			elem->next->prev = elem;
			elem->prev = NIL;
			elem->key = key;
			NIL->next = elem;
				}
		else if (op == "delete")
		{
					CL* elem = Search(key);
			if (elem == NIL)
				continue;
			
			elem->prev->next = elem->next;
			elem->next->prev = elem->prev;
			delete elem;
		}
		else if (op == "deleteFirst")
		{
			CL* elem = NIL->next;
			elem->prev->next = elem->next;
			elem->next->prev = elem->prev;
			delete elem;
		}
		else if (op == "deleteLast")
		{
			CL* elem = NIL->prev;
			elem->prev->next = elem->next;
			elem->next->prev = elem->prev;
			delete elem;
		}
	}
	CL* ptr = NIL->next;
	bool isStart = true;
	while(true)
	{
		if(ptr == NIL)
			break;
		if (!isStart)
		{
			printf(" ");
		}
				
		printf("%d", ptr->key);
			isStart = false;
		ptr = ptr->next;
	}
	printf("\n");
	
	delete NIL;
	return 0;
}