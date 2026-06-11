#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class node {
public:
	node() {
		parent = -1;
		children.clear();
		depth = -1;
	}
	int parent;
	vector<int> children;
	int depth;
};

int n;
node d[100000];

int main(void) {
	int a,k,c;
	cin >> n;
	for(int i =0;i<n;i++){
		cin >> a >> k;
		for(int j = 0;j < k;j++){
			cin >> c;
			d[a].children.push_back(c);
			d[c].parent = a;
		}
	}
	queue<int> q;
	for(int i = 0;i < n;i++){
		if(d[i].parent == -1){
			d[i].depth = 0;
			q.push(i);
		}
	}
	while(!q.empty()){
		int v = q.front();q.pop();
		for(auto& e:d[v].children){
			if(d[e].depth == -1){
				d[e].depth = d[v].depth + 1;
				q.push(e);
			}
		}
	}
	for(int i = 0;i < n;i++){
		cout << "node " << i << ": parent = " << d[i].parent << ", depth = " << d[i].depth << ", ";
		if(d[i].parent == -1) cout << "root";
		else if(d[i].children.size() == 0) cout << "leaf";
		else cout << "internal node";
		cout << ", [";
		for(int j = 1;j < ((signed)d[i].children.size());j++) cout << d[i].children[j-1] << ", ";
		if(d[i].children.size() != 0)cout << d[i].children[d[i].children.size()-1];
		cout << "]" << endl;
	}
}

