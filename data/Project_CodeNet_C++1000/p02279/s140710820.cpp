#include <iostream>
#include <vector>

using namespace std;

class Node
{
  public:
    Node() {MyID = ParentID = -1; Depth = 0; }

    int MyID;
    int ParentID;
    int Depth;
    vector<int> ChildrenID;

    void Print()
    {
      //node 0: parent = 1, depth = 1, leaf, []
      cout << "node " << MyID << ": "
	<< "parent = " << ParentID << ", " 
	<< "depth = " << Depth << ", "
	<< (ParentID == -1 ? "root, " : ChildrenID.size() > 0 ? "internal node, " : "leaf, ");

      cout << "[";
      for(int i = 0; i < ChildrenID.size(); ++i)
	cout << ChildrenID[i] << (ChildrenID.size() - 1 == i ? "" : ", ");
      cout << "]" << endl;


    }
};

Node *Nodes;

int main()
{
  int N;
  cin >> N;

  Nodes = new Node[N];

  for(int i = 0; i < N; ++i)
    Nodes[i].MyID = i;

  for(int i = 0; i < N; ++i)
  {
    int NodeID; cin >> NodeID;
    int K; cin >> K;

    for(int k = 0; k < K; ++k)
    {
      int k_id; cin >> k_id;
      Nodes[NodeID].ChildrenID.push_back(k_id);
      Nodes[k_id].ParentID = NodeID;
    }
  }

  for(int i = 0; i < N; ++i)
  {
    int p = i;
    while (Nodes[p].ParentID != -1)
    {
      Nodes[i].Depth++;
      p = Nodes[p].ParentID;
    }
  }


  for(int i = 0; i < N; ++i)
    Nodes[i].Print();

  delete [] Nodes;

  return 0;
}

