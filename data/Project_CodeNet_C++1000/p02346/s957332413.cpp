#include <iostream>
#include <algorithm>
#define INF 2147483647
using namespace std;
int tree[(1<<18)];
int n,q;
void add(int i,int x) {
  i+=(n-1);
  tree[i] += x;
  while(i!=0){
    i=(i-1)/2;
    tree[i] += x;
  }
}
int getsum(int a ,int b,int ima,int L,int R){
  if(R<=a || b<=L) return 0;
  if(a<=L && R<=b) return tree[ima];
  int M = (R+L)/2;
  return getsum(a,b,ima*2+1,L,M)+getsum(a,b,ima*2+2,M,R);
}

int main(){
  cin >> n >>q;
  int N=1;
  while(N<n)N*=2;
  n=N;
  while(q--){
    int com,x,y;
    cin >>com >> x >> y;
    if(com == 0) add(x-1,y);
    if(com == 1) cout << getsum(x-1,y,0,0,n) <<endl;
  }
  return 0;
}