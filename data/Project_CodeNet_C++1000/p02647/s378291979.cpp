#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

const int MAXSSTN = 200010;
class StarrySkyTree{
public:
  int size=0;
  int depth=0; // the depth of the tree
  int best=0;  // the index of maximum element
  int start=0; // the initial index of inputs
  long long dat_add[4 * MAXSSTN];
  long long dat[4 * MAXSSTN];
  
  StarrySkyTree(int n){
    size=n;
    while((1<<depth)<n)depth++;
    start=(1<<depth)-1;
    for(int i=start;i<(1<<(depth+1));i++){
      if(i<start+n)
	dat[i]=0;
      else
	dat[i]=1e15;
    }
    for(int i=start;i<start+n;i++){
      int tmp=i;
      while(par(tmp)!=-1){
	dat[par(tmp)]=min(dat[tmp],dat[(tmp+1)/2*4-1-tmp]);
	tmp=par(tmp);
      }
    }
    int i=0;
    while(i<start)i=(dat[i]==dat[2*i+1])?2*i+1:2*i+2;
    best=i-start;
  }
  long long max_element(int a, int b){ return max_element(a, b, 0, 0, (1<<depth)); }
  void add(int s, int t, int x){ add(s, t, 0, 0, (1<<depth), x); }
  void add(int i, int x){ add(i, i + 1, 0, 0, (1<<depth), x); }

  int par(int i){
    if(i==0)
      return -1;
    return (i-1)/2;
  }
  
  void clear() {
    for(int i=start;i<(1<<(depth+1));i++){
      if(i<start+size)
	dat[i]=0;
      else
	dat[i]=1e15;
    }
    for(int i=start;i<start+size;i++){
      int tmp=i;
      while(par(tmp)!=-1){
	dat[par(tmp)]=min(dat[tmp],dat[(tmp+1)/2*4-1-tmp]);
	tmp=par(tmp);
      }
    }
    int i=0;
    while(i<start)i=(dat[i]==dat[2*i+1])?2*i+1:2*i+2;
    best=i-start;
    
    REP(i,4*MAXSSTN)dat_add[i]=0;
  }

  void update(int d,long long x){
    int i=d+start;
    dat[i]=x;
    while(par(i)!=-1){
      dat[par(i)]=min(dat[i],dat[(i+1)/2*4-1-i]);
      i=par(i);
    }
    i=0;
    while(i<start){
      i=(dat[i]==dat[2*i+1])?2*i+1:2*i+2;
    }
    best=i-start;
  }
  void dump(){
    for(int i=0;i<(1<<(depth+1));i++){
      cerr<<dat[i]<<" ";
    }
    cerr<<endl;
  }
private:
  long long max_element(int a, int b, int k, int l, int r){
    if(b <= l || r <= a) return 1e15;
    if(a <= l && r <= b) return dat[k] + dat_add[k];

    long long vl = max_element(a, b, k * 2+1, l, (l + r) / 2);
    long long vr = max_element(a, b, k * 2+2, (l + r) / 2, r);
    return min(vl, vr) + dat_add[k];
  }
  void add(int a, int b, int k, int l, int r, long long x){
    if(b <= l || r <= a) return;
    if(a <= l && r <= b){
      dat_add[k] += x;
    }else{
      add(a, b, k * 2+1, l, (l + r) / 2, x);
      add(a, b, k * 2+2, (l + r) / 2, r, x);
      dat[k] = min(dat[k * 2+1] + dat_add[k * 2+1], dat[k * 2 + 2] + dat_add[k * 2 + 2]);
    }
  }
};

int n,k;
int a[200000];
 
int main(){
  cin>>n>>k;
  REP(i,n)cin>>a[i];
  if(k >= 41){
    REP(i,n)cout<<n<<" ";
    cout<<endl;
    return 0;
  }
 
  StarrySkyTree sst(n);
  REP(i,k){
    REP(j,n)sst.update(j,0);
    REP(j,n){
      sst.add(max(0,j-a[j]),min(n-1,j+a[j])+1,1);
    }
    REP(j,n){
      if(a[j]!=n || !i)
	      a[j]=sst.max_element(j,j+1);
    }
    sst.clear();
  }
 
  REP(i,n)cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}
