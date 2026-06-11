#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctype.h>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;
#define NIL -1

struct Tree
 {
 	int p,l,r;
 };

Tree *T;
int *D;
string *S;

void depth(int t,int dep){
	D[t] = dep;

	if(T[t].r != NIL) 
		depth(T[t].r,dep);

	if(T[t].l != NIL)
		depth(T[t].l,dep+1);
}

void type(int t){
	if(T[t].p == NIL){
		S[t] = "root, ";
	}else if(T[t].l != NIL){
		S[t] = "internal node, ";
	}else{
		S[t] = "leaf, ";
	}

	if(T[t].r != NIL) type(T[t].r);

	if(T[t].l != NIL) type(T[t].l);
}

void family(int t){
	if(T[t].l != NIL){
		t = T[t].l;
		cout << t;
		while(1){
			if(T[t].r != NIL){
				t = T[t].r;
				cout << ", ";
				cout << t;
			}else{
				break;
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	T = new Tree[n];
	D = new int[n];
	S = new string[n];
	for(int i = 0;i < n;i++){
		T[i].p = T[i].l = T[i].r = NIL;
	}
	int v,d,num,l;
	for(int i = 0;i < n;i++){
		cin >> v >> d;
		for(int j = 0;j < d;j++){
			cin >> num;
			if(j == 0) T[v].l = num;
			else T[l].r = num;
			l = num;
			T[num].p = v;
		}
	}
	int root;
	for(int i = 0;i < n;i++){
		if(T[i].p == NIL) root = i;
	}
	depth(root,0);
	type(root);
	for(int i = 0;i < n;i++){
		cout << "node " << i << ": ";
		cout << "parent = " << T[i].p << ", ";
		cout << "depth = " << D[i] << ", ";
		cout << S[i];
		cout << "[";
		family(i);
		cout << "]" << endl;
	}

	return 0;
}