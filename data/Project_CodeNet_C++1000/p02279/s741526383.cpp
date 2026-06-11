#include<iostream>
// #include<fstream>
using namespace std;
#define MAX 100001
#define NIL -1

// leftChild represent a node's child which is on the most left side 
// rightSibling represent a brother node which is to the right of the current node
struct Node { int parent, leftChild, rightSibling; };

Node nodes[MAX];
int n, depthOfNode[MAX];

void printNode(int nodeId);
void setDepth(int currentNode, int depth);

int main(){
	int i,j; // for loop
	int childNode, parentNode, degreeOfNode, previousChildNode, root;
	// ifstream input;
	// input.open("input");

	cin >> n;
	// input >> n;

	// initialize
	for (i = 0; i < n; i++)
		nodes[i].parent = nodes[i].leftChild = nodes[i].rightSibling = NIL;

	for (i = 0; i < n; i++){
		cin >> parentNode >> degreeOfNode;
		// input >> parentNode >> degreeOfNode;
	
		for (j = 0; j < degreeOfNode; j++){
			cin >> childNode;
			// input >> childNode;

			if (j == 0)
				nodes[parentNode].leftChild = childNode;
			else
				nodes[previousChildNode].rightSibling = childNode;

			previousChildNode = childNode;
			nodes[childNode].parent = parentNode;
		}

	}

	for (i = 0; i < n; i++) {
		if (nodes[i].parent == NIL) {
			root = i;
			break;
		}
	}

	// recursively set depth
	setDepth(root, 0);

	for (i = 0; i < n; i++) {
		printNode(i);
	}

	return 0;
}

void setDepth(int currentNode, int depth) {
	depthOfNode[currentNode] = depth;
	if (nodes[currentNode].leftChild != NIL)
		setDepth(nodes[currentNode].leftChild, depth + 1);
	if (nodes[currentNode].rightSibling != NIL)
		setDepth(nodes[currentNode].rightSibling, depth);
}

void printNode(int nodeId) {
	int i, childNode;
	cout << "node " << nodeId << ": ";
	cout << "parent = " << nodes[nodeId].parent << ", ";
	cout << "depth = " << depthOfNode[nodeId] << ", ";

	if (nodes[nodeId].parent == NIL)
		cout << "root, ";
	else if (nodes[nodeId].leftChild == NIL)
		cout << "leaf, ";
	else
		cout << "internal node, ";

	cout << "[";

	for (i = 0, childNode = nodes[nodeId].leftChild; 
		childNode != NIL;
		i++, childNode = nodes[childNode].rightSibling) 
	{
		if (i != 0) cout << ", ";

		cout << childNode;
	}

	cout << "]" << endl;
}