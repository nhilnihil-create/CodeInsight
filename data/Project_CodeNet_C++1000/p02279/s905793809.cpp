#include <iostream>
#include <list>
#include <vector>

using namespace std;

enum TYPE{
	ROOT,
	LEAF,
	NODE,
};
string TYPESTR[]={"root","leaf","internal node"};

class Node{
	
	int id;
	int depth;
	//TYPE node_type;
public:	
    Node(int id){this->id = id;}
	Node* parent;
	list<Node*> child_list;
	int getChildNum(){return child_list.size();}
	int getId(){return id;}
	int getDepth(){return depth;}
	TYPE getType();
	void setDepth(int depth);
};

void output(vector<Node*> t);

int main(){
	
	int n = 0;
	cin >> n ;
	vector<Node*> table;
	table.resize(n);
	//全テーブルをノードで埋める
	for(int i=0;i<n;i++){
		table[i]=new Node(i);
	}
	for(int i=0;i<n;i++){
		int id=0;
		cin >> id;
		int child_num=0;
		cin >> child_num;
		table[id]->child_list.resize(child_num);
		for(auto itr = table[id]->child_list.begin() ; itr != table[id]->child_list.end(); itr++){
			int child = 0;
			cin >> child;
			//ノードの子を教える
			*itr = table[child];
			//ノードの親を教える
			table[child]->parent = table[id];
		}
	}
	//rootを決める
	Node* root = table[0];
	while(root->parent){
		root = root->parent;
	}
	//root->parent = -1;
	root->setDepth(0);
	
	output(table);
	return 0;
}

void Node::setDepth(int depth){
	this->depth = depth;
	for(auto /*list<Node*>::iterator*/ itr = child_list.begin(); itr != child_list.end(); itr++){
		(*itr)->setDepth(depth+1);
	}
}
TYPE Node::getType(){
	if(!parent){
		return ROOT;
	}
	if(child_list.size()==0){
		return LEAF;
	}
	return NODE;
}

void output(vector<Node*> t){
	int size = t.size();
	for(int i=0;i<size; i++){
		cout << "node " << i << ": ";
		int parent = (t[i]->parent) ? (t[i]->parent->getId()) : -1;
		cout << "parent = " << parent <<", ";
		cout << "depth = " << t[i]->getDepth() << ", ";
		cout << TYPESTR[t[i]->getType()] << ", ";
		cout << "[";
		for(auto itr =t[i]->child_list.begin(); itr!= t[i]->child_list.end(); itr++){
			if(itr != t[i]->child_list.begin()){
				cout << ", ";
			}
			cout << (*itr)->getId() ;
		}
		cout << "]" << endl;
	}
}


