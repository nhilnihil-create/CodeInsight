#include"iostream"
#include"vector"
#include"stdio.h"
using namespace std;
class branch
{
public:
  int id;
  int p;
  int sibling;
  int right;
  int left;
};
vector<branch> tree;
int preParse(int id)
{
  if(id==-1)
    {
      return 0;
    }
  cout<<" "<<id;
  preParse(tree[id].left);
  preParse(tree[id].right);
}
int inParse(int id)
{
  if(id==-1)
    {
      return 0;
    }
  inParse(tree[id].left);
  cout<<" "<<id;
  inParse(tree[id].right);
}
int postParse(int id)
{
  if(id==-1)
    {
      return 0;
    }
  postParse(tree[id].left);
  postParse(tree[id].right);
  cout<<" "<<id;
}
int main()
{
  branch buf;
  buf.p=-1;
  buf.sibling=-1;
  int n;
  int hId;
  cin>>n;
  for(int i=0;i<n;i++)
    {
      tree.push_back(buf);
    }
  for(int i=0;i<n;i++)
    {
      int id;
      int right,left;
      cin>>id;
      tree[id].id=id;
      cin>>left;
      tree[id].left=left;
      cin>>right;
      tree[id].right=right;
      if(right!=-1)
        {
          tree[right].p=id;
          tree[right].sibling=left;
        }
      if(left!=-1)
        {
          tree[left].p=id;
          tree[left].sibling=right;
        }
    }
  for(int i=0;i<tree.size();i++)
    {
      if(tree[i].p==-1)
        {
          hId=tree[i].id;
        }
    }
  cout<<"Preorder"<<endl;
  preParse(hId);
  cout<<endl;
  cout<<"Inorder"<<endl;
  inParse(hId);
  cout<<endl;
  cout<<"Postorder"<<endl;
  postParse(hId);
  cout<<endl;
  return 0;
}
