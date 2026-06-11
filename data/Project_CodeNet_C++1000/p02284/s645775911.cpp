#include"iostream"
#include"vector"
using namespace std;
class branch
{
public:
  int key;
  branch *p;
  branch *left,*right;
  branch(){}
  branch(int key,branch *p)
  {
    this->key=key;
    this->p=p;
    this->left=NULL;
    this->right=NULL;
  }
};
branch *tree;
void insert(int z)
{
  branch *buf;
  branch *y=NULL;
  branch *x=tree;
  while(x!=NULL)
    {
      y=x;
      if(z<x->key)
        {
          x=x->left;
        }
      else
        {
          x=x->right;
        }
    }
  buf=new branch(z,y);
  if(y==NULL)tree=buf;
  else if(buf->key<y->key)y->left=buf;
  else y->right=buf;
}
int search(int key,branch *p)
{
  if(p==NULL)return 0;
  if(p->key==key)return 1;
  if(key<p->key)
    {
      return search(key,p->left);
    }
  else
    {
      return search(key,p->right);
    }
  return 0;
}
int preParse(branch *p)
{
  if(p==NULL)
    {
      return 0;
    }
  cout<<" "<<p->key;
  preParse(p->left);
  preParse(p->right);
}
int find(int key)
{
  branch *p=tree;
  return search(key,p);
}
int inParse(branch *p)
{
  if(p==NULL)
    {
      return 0;
    }
  inParse(p->left);
  cout<<" "<<p->key;
  inParse(p->right);
}
int postParse(branch *p)
{
  if(p==NULL)
    {
      return 0;
    }
  postParse(p->left);
  postParse(p->right);
  cout<<" "<<p->key;
}
int main()
{
  tree=NULL;
  int m;
  char cmd[20];
  cin>>m;
  for(int i=0;i<m;i++)
    {
      cin>>cmd;
      if(cmd[0]=='i')
        {
          int n;
          cin>>n;
          insert(n);
        }
      else if(cmd[0]=='p')
        {
          inParse(tree);
          cout<<endl;
          preParse(tree);
          cout<<endl;
        }
      else if(cmd[0]=='f')
        {
          int n;
          cin>>n;
          if(find(n))cout<<"yes"<<endl;
          else cout<<"no"<<endl;
        }
    }
  return 0;
}
