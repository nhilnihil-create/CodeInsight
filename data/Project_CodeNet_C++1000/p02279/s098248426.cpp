#include"iostream"
#include"stdio.h"
#include"vector"
#include"stdlib.h"

using namespace std;

class branch
{
private:
public:
  int id;
  int p;
  int depth;
  vector<int> c;
  branch()
  {
  }
  void print()
  {
    cout<<"node "<<id<<": parent = "<<p<<", depth = "<<depth<<", ";
    if(p==-1)
      {
        cout<<"root, [";
      }
    else if(!c.size())
      {
        cout<<"leaf, [";
      }
    else
      {
        cout<<"internal node, [";
      }
    if(0<c.size())
      {
        cout<<c[0];
        for(int i=1;i<c.size();i++)
          {
            cout<<", "<<c[i];
          }
      }
    cout<<"]"<<endl;
  }
};
vector<branch> tree;
int countDepth(int id)
{
  if(tree[id].p!=-1)return 1+countDepth(tree[id].p);
  return 0;
}

int main()
{
  branch buf;
  int n;
  cin>>n;
  buf.p=-1;
  for(int i=0;i<n;i++)
    {
      tree.push_back(buf);
    }
  for(int i=0;i<n;i++)
    {
      int id;
      int k;
      cin>>id;
      tree[id].id=id;
      cin>>k;
      for(int j=0;j<k;j++)
        {
          int c;
          cin>>c;
          tree[id].c.push_back(c);
          tree[c].p=id;
        }
    }
  for(int i=0;i<tree.size();i++)
    {
      tree[i].depth=countDepth(tree[i].id);
      tree[i].print();
    }
  return 0;
}
