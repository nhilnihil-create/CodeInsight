#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1<<17;
int bit[MAX_N+1],n;

int sum(int i){
  int s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return s;
}

void add(int i,int x){
  while(i<=n){
    bit[i]+=x;
    i+=i&-i;
  }
}

int main(){
  int q;
  cin>>n>>q;
  while(q--){
    int com,x,y;
    cin>>com>>x>>y;
    if(com==0)add(x,y);
    if(com==1)cout<<sum(y)-sum(x-1)<<endl;;
  }
}