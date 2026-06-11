#include <bits/stdc++.h>
using namespace std;

#define N 100001
//root??§??????????????????
#define Origin -1

int depth(int);
void c_out(int);

struct Node{
	int p;
	int left;
	int right;
};

struct Node tree[N];
int cnt;

int main(){
	int n, k, new_node, child, l;
	
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		tree[i].p = tree[i].left = tree[i].right = Origin;
	}
	
	for(int i = 0 ; i < n ; i++){
		cin >> new_node >> k;
		for(int j = 0 ; j < k ; j++){
			cin >> child;
			if(j == 0){
				tree[new_node].left = child;
			}else{
				tree[l].right = child;
			}
			
			l = child;
			tree[child].p = new_node;
		}
	}
	//??¶??????????????¨??????
	for(int i = 0 ; i < n ; i++){
		cnt = 0;
		
	cout << "node " << i << ": parent = " << tree[i].p << ", depth = " << depth(i) << ", ";
	if(tree[i].p == Origin){
		cout << "root, ";
	}
	else if(tree[i].left == Origin){
		cout << "leaf, ";
	}else{
		cout << "internal node, ";
	}
		cout << "[";
		
	cnt = 0;
	c_out(tree[i].left);
	cout << "]" << endl;
	}
	return 0;
}

//??±???????????°??§?±???????
int depth(int x){
	if(tree[x].p != Origin){
		cnt++;
		return depth(tree[x].p);
	}else{
		return cnt;
	}
}

//????????????
void c_out(int y){
	if(y != Origin){
		if(cnt != 0){
			cout << ", ";
		}
		
		cnt++;
		cout << y;
		c_out(tree[y].right);
	}
}