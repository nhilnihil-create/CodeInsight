#include<iostream>
#include<algorithm>
using namespace std;
int tree[(1<<18)];

void add(int i,int x){
  i+=((1<<17)-1);
  tree[i]+=x;
  while(i){
    i=(i-1)/2;
    tree[i]=tree[i*2+1]+tree[i*2+2];
  }
}

int getsum(int a,int b,int n,int l,int r){
   if(r<=a || b<=l) return 0;
   if(a<=l && r<=b)return tree[n];
    int m=(l+r)/2;
   return getsum(a,b,n*2+1,l,m)+getsum(a,b,n*2+2,m,r);
}


int main(){
  int n,q,a,b,c;
  cin>>n>>q;
  for(int i=0;i<q;i++){
    cin>>a>>b>>c;
    if(a==1){
      cout<<getsum(b-1,c,0,0,(1<<17))<<endl;
    }
    else add(b-1,c);
  }
  return 0;
}