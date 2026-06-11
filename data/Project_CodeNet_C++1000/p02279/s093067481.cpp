#include <iostream>
#include <cstdio>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>

using namespace std;

struct node{
    node(){
		parent=-1;
		depth=0;
	}
	void set(const int cLeaf){
		leaf.resize(cLeaf);
		for(int i=0;i<cLeaf;i++){
			cin>>leaf[i];
		}
	}
	int parent;
	int depth;
	vector<int> leaf;
};

int main()
{
	int N,id,k;
	queue<int> que;
	node dnode[100000];
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>id>>k;
		dnode[id].set(k);
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<dnode[i].leaf.size();j++){
			dnode[dnode[i].leaf[j]].parent=i;
		}
	}
	for(int i=0;i<N;i++){
		if(dnode[i].parent==-1){
			for(que.push(i);!que.empty();que.pop()){
				for(int j=0;j<dnode[que.front()].leaf.size();j++){
					dnode[dnode[que.front()].leaf[j]].depth=dnode[que.front()].depth+1;
					if(dnode[dnode[que.front()].leaf[j]].leaf.size()){
						que.push(dnode[que.front()].leaf[j]);
					}
				}
			}
			break;
		}
	}
	for(int i=0;i<N;i++){
		cout<<"node "<<i<<": parent = "<<dnode[i].parent<<", depth = "<<dnode[i].depth;
		if(dnode[i].parent==-1){
			cout<<", root, [";
			for(int j=0;j<dnode[i].leaf.size();j++){
				if(j){
					cout<<", ";
				}
				cout<<dnode[i].leaf[j];
			}
		}else if(dnode[i].leaf.size()){
			cout<<", internal node, [";
			for(int j=0;j<dnode[i].leaf.size();j++){
				if(j){
					cout<<", ";
				}
				cout<<dnode[i].leaf[j];
			}
		}else{
			cout<<", leaf, [";
		}
		cout<<']'<<endl;
	}
}