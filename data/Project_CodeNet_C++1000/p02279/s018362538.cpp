#include <iostream>
using namespace std;
struct node{int p,l,r;};
node t[100000];
int n,d[100000];
void dp(int p,int d1){
  d[p]=d1;
  if(t[p].l!=-1) dp(t[p].l,d1+1);
  if(t[p].r!=-1) dp(t[p].r,d1);
}
int main(){

  int tmp1,tmp2,cnt;
  cin>>n;

  for(int i=0;i<n;i++) t[i].p=t[i].l=t[i].r=-1;
  for(int i=0;i<n;i++){
    cin>>tmp1>>cnt;
    int tmpl=-1;
    for(int j=0;j<cnt;j++){
      cin>>tmp2;
      if(j==0) t[tmp1].l=tmp2;
      t[tmp2].p=tmp1;
      if(tmpl!=-1) t[tmpl].r=tmp2;
      tmpl=tmp2;
    }
  }
  int st;
  for(int i=0;i<n;i++) if(t[i].p==-1) st=i;

  dp(st,0);

  for(int i=0;i<n;i++){
    cout<<"node "<<i<<": parent = "<<t[i].p<<", depth = "<<d[i]<<", ";
    if(t[i].p==-1) cout<<"root, [";
    else if(t[i].l==-1){ cout<<"leaf, []"<<endl; continue;}
    else cout<<"internal node, [";
    tmp1=t[i].l;
    for(int j=0;tmp1!=-1;j++){
      if(j) cout<<", ";
      cout<<tmp1;
      tmp1=t[tmp1].r;
    }
    cout<<"]"<<endl;
  }

  return 0;

}