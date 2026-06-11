#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

struct Node{
	int parent = -1;
	int left_child = -1;
	int right_brother = -1;
};

int cal_depth(vector<Node>& a, int d, int n){
	if(a[n].parent == -1) return d;
	d++;
	int depth = cal_depth(a, d, a[n].parent);
	return depth;
}

int main(){
	int n;
	cin >> n;
	vector<Node> a(n);
	rep(i,n){
		int id, k;
		cin >> id >> k;
		int px = -1;
		rep(j, k){
			int x;
			cin >> x;
			if(j == 0) a[id].left_child = x;
			a[x].parent = id;
			if(px != -1) a[px].right_brother = x;
			px = x;
		}
	}
	rep(i, n){
		cout << "node " << i << ": ";
		cout << "parent = " << a[i].parent << ", ";
		int depth = cal_depth(a, 0, i);
		cout << "depth = " << depth << ", ";
		if(a[i].parent == -1){
			cout << "root, ";
		}else if(a[i].left_child == -1){
			cout << "leaf, ";
		}else{
			cout << "internal node, ";
		}
		cout << "[";
		int nowp = a[i].left_child;
		while(nowp != -1){
			cout << nowp;
			nowp = a[nowp].right_brother;
			if(nowp == -1) break;
			cout << ", ";
		}
		cout << "]" << endl;
	}
}

