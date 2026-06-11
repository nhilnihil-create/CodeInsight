// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_7_A&lang=jp
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

class Node{
protected:
  int id;
  Node* parent;
  vector<Node*> children;
  void becomeParentOf(Node*);
public:
  Node();
  void becomeChildOf(Node*);
  void setId(int);
  bool isRoot();
  bool isLeaf();
  int getDepth();
  int getParentId();
  int getId();
  string getType();
  string getListOfChildren();
};

void Node::setId(int aId){
  id = aId;
}

Node::Node(){
  id = NULL;
  parent = NULL;
  children.clear();
}

void Node::becomeChildOf(Node* aParent){
  parent = aParent;
  parent->becomeParentOf(this);
}

void Node::becomeParentOf(Node* child){
  children.push_back(child);
}

bool Node::isRoot(){
  return parent == NULL;
}

bool Node::isLeaf(){
  return children.empty();
}

int Node::getDepth(){
  if (parent == NULL){
    return 0;
  }
  else{
    return parent->getDepth() + 1;
  }
}

int Node::getId() {
	return id;
}

int Node::getParentId() {
	if (parent == NULL) {
		return -1;
	}
	else{
		return parent->getId();
	}
}

string Node::getType() {
	if (isRoot()) {
		return "root";
	}
	else if (isLeaf()) {
		return "leaf";
	}
	else {
		return "internal node";
	}
}

string toString(int number) {
	stringstream ss;
	ss << number;
	return ss.str();
}

string Node::getListOfChildren() {
	if (children.empty()) {
		return "[]";
	}
	string listStr = "[";
	for (vector<Node*>::iterator it = children.begin(); it != children.end(); it++) {
		listStr += toString((*it)->getId());
		if (it + 1 != children.end()) {
			listStr += ", ";
		}
	}
	listStr += "]";
	return listStr;
}

vector<string> split(const string &str, char delim) {
	istringstream iss(str); string tmp; vector<string> res;
	while (getline(iss, tmp, delim)) res.push_back(tmp);
	return res;
}

int main(){
	string strNumOfNodes;
	getline(cin, strNumOfNodes);
	int numOfNodes = atoi(strNumOfNodes.c_str());
	
	Node* nodes = new Node[numOfNodes];
	for (int i = 0; i < numOfNodes; i++) {
		nodes[i].setId(i);
	}
	
	for (int i = 0; i < numOfNodes; i++) {
		string line;
		getline(cin, line);
		
		vector<string> splitLine = split(line, ' ');
		vector<int> splitLineInt;
		for (vector<string>::iterator it = splitLine.begin(); it != splitLine.end(); it++) {
			splitLineInt.push_back(atoi((*it).c_str()));
		}

		int numOfChildren = splitLineInt.size() - 2;
		int parentId = splitLineInt[0];
		for (int i = 0; i < numOfChildren; i++) {
			int childId = splitLineInt[i + 2];
			nodes[childId].becomeChildOf(&nodes[parentId]);
		}
	}

	for (int i = 0; i < numOfNodes; i++) {
		cout << "node " << i << ": ";
		cout << "parent = " << nodes[i].getParentId() << ", ";
		cout << "depth = " << nodes[i].getDepth() << ", ";
		cout << nodes[i].getType() << ", ";
		cout << nodes[i].getListOfChildren();
		cout << endl;
	}

	delete[] nodes;

//	string end;
//	cin >> end;

	return 0;
}