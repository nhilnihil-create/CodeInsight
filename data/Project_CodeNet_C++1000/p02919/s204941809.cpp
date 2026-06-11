#include <bits/stdc++.h>
using namespace std;

int MAX_N=262144;
vector<int64_t> seg(MAX_N*2-1);
int64_t qu(int a,int b,int k,int l, int r){
  if(r<=a||b<=l){
    return -1;
  }
  else if(a<=l&&r<=b){
    return seg[k];
  }
  else{
    int64_t X=qu(a,b,k*2+1,l,(l+r)/2);
    int64_t Y=qu(a,b,k*2+2,(l+r)/2,r);
    return max(X,Y);
  }
}
void chmax(int64_t a,int b){
  int D=MAX_N-1+b;
  seg[D]=a;
  while(D>0){
    D--;
    D/=2;
    seg[D]=max(seg[2*D+1],seg[2*D+2]);
  }
}


int main() {
  int N,l,r;
  cin>>N;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    chmax(a,i);
    p[a-1]=i;
  }
  int64_t Z=0;
  for(int i=N-1;i>0;i--){
    int a=p[i-1];
    int64_t A=N-a,B=N-a,C=a+1,D=a+1;
    if(qu(a,N,0,0,MAX_N)>i){
      l=a+1,r=N;
      while(r-l>1){
        int X=(l+r)/2;
        if(qu(a,X,0,0,MAX_N)>i){
          r=X;
        }
        else{
          l=X;
        }
      }
      A=r-a-1;
      if(qu(A+1+a,N,0,0,MAX_N)>i){
        l=A+1+a,r=N;
        while(r-l>1){
          int X=(l+r)/2;
        if(qu(A+1+a,X,0,0,MAX_N)>i){
          r=X;
        }
        else{
          l=X;
        }
        }
        B=r-a-1;
      }
    }
    if(qu(0,a,0,0,MAX_N)>i){
      l=0,r=a;
      while(r-l>1){
        int X=(l+r)/2;
        if(qu(X,a,0,0,MAX_N)>i){
          l=X;
        }
        else{
          r=X;
        }
      }
      C=a-r+1;
      if(qu(0,l,0,0,MAX_N)>i){
        r=l,l=0;
        while(r-l>1){
          int X=(l+r)/2;
          if(qu(X,a-C,0,0,MAX_N)>i){
            l=X;
          }
          else{
            r=X;
          }
        }
        D=a-l;
      }
    }
    int64_t Q=A*(D-C)+(B-A)*C;
    Q*=i;
    Z+=Q;
  }
  cout<<Z<<endl;
}