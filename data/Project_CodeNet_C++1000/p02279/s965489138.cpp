#include <iostream>
#include <string>
#include <vector>

struct TNode
{
	int Index;
	TNode* Parent;
	std::vector<TNode*> Children;
	
	TNode();
};

TNode::TNode()
{
	Index = -1;
	Parent = NULL;
	Children.clear();
}

typedef std::vector<TNode> TRootedTree;

void AddNode(TRootedTree& Tree)
{
	int Index;
	std::cin >> Index;
	Tree[Index].Index = Index;
	int ChildrenCount;
	std::cin >> ChildrenCount;
	Tree[Index].Children.resize(ChildrenCount);
	for(int i = 0; i < ChildrenCount; i++){
		int ChildIndex;
		std::cin >> ChildIndex;
		Tree[Index].Children[i] = &(Tree[ChildIndex]);
		Tree[ChildIndex].Parent = &(Tree[Index]);
	}
}

int GetDepth(const TNode& Node, int Depth = 0)
{
	if(!Node.Parent) return Depth;
	return GetDepth(*(Node.Parent), Depth + 1);
}

std::string GetType(const TNode& Node)
{
	if(!Node.Parent) return "root";
	if(Node.Children.empty()) return "leaf";
	return "internal node";
}

void OutputNode(const TNode& Node)
{
	std::cout << "node " << Node.Index << ": ";
	int ParentIndex = Node.Parent != NULL ? Node.Parent->Index : -1;
	std::cout << "parent = " << ParentIndex << ", ";
	std::cout << "depth = " << GetDepth(Node) << ", ";
	std::cout << GetType(Node) << ", ";
	std::cout << "[";
	for(unsigned int i = 0; i < Node.Children.size(); i++){
		std::cout << Node.Children[i]->Index;
		if(i < Node.Children.size() - 1) std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

int main()
{
	int Count;
	std::cin >> Count;
	TRootedTree Tree(Count);
	for(int i = 0; i < Count; i++){
		AddNode(Tree);
	}
	
	for(int i = 0; i < Count; i++){
		OutputNode(Tree[i]);
	}
	return 0;
}