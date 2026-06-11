#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long
#define MAX 100005
#define NIL -1

struct Node{
	int parent, left, right;
};
Node T[MAX];
int n, D[MAX], H[MAX];

void setDepth(int u, int d){
	if(u == NIL) return;
	D[u] = d;
	setDepth(T[u].left, d+1);
	setDepth(T[u].right, d+1);
}

int setHeight(int u){
	int h1 = 0, h2 = 0;
	if(T[u].left != NIL)
		h1 = setHeight(T[u].left) + 1;
	if(T[u].right != NIL)
		h2 = setHeight(T[u].right) + 1;
	return H[u] = (h1 > h2 ? h1 : h2);
}

int main(){
	int x, a;
	cin >> x >> a;
	if(x < a) cout << 0 << endl;
	else cout << 10 << endl;

}