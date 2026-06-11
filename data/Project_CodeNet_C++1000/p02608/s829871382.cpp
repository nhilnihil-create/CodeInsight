#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define READ(FILE) freopen(FILE,"r",stdin)
#define WRITE(FILE) freopen(FILE,"w",stdout)
#define loop(i,s,e) for(int i=s;i<e;i++)
#define mego fast();
using namespace std;
void fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll lcm(ll x, ll y)
{
    return (x*y)/__gcd(x,y);
}
int sum(string s)
{
    int x=0,sz=s.size();
    loop(i,0,sz)x+=(s[i]-'0');
    return x;
}
/*
struct node
{
int data;
node *link;
};
typedef node* nodeptr;
void head_insert(nodeptr& head,int x)
{
    nodeptr tmp;
    tmp=new node;
    tmp->data=x;
    tmp->link=head;
    head=tmp;
}
nodeptr search(nodeptr head,int x)
{
    nodeptr cur=head;
    if(cur ==  nullptr)return cur;
    while(cur->data!=x&&cur->link!=nullptr)
    {
        cur=cur->link;
    }
    if(cur->data==x)return cur;
    else return nullptr;
}
void show(nodeptr head)
{
    nodeptr cur=head;
    if(cur==nullptr)return;
   // cout<<head->data<<" ";
    while(cur->link!=nullptr){
        cout<<cur->data<<" ";
        cur=cur->link;
    }
    cout<<endl;
}
*/

int main()
{
    mego
   int n,id,m,x=0;
   unordered_map<int,int>f;
   loop(i,1,101)
   loop(j,1,101)
   loop(k,1,101)
   {
       x=(i*i);
       x+=(j*j);
       x+=(k*k);
       x+=(i*j);
       x+=(i*k);
       x+=(j*k);
      f[x]++;

   }
   cin>>n;
   loop(i,1,n)
   cout<<f[i]<<endl;
   cout<<f[n];
    return 0;
}
