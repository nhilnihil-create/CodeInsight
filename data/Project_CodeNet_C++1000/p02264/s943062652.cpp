#include<bits/stdc++.h>
#define N 100000
using namespace std;
int head,tail,an;
struct P{
  int t;
  int id; 
};
int main(){
  int n,q;
  P Q[N];
  string s[N];
  cin>>n>>q;
  for(int i=0;i<n;i++){
    cin>>s[i]>>Q[i].t;
    Q[i].id=i;
    tail++;
  }
  while(tail!=head){
    int a=Q[head%N].t;
    Q[head%N].t-=q;
    if(Q[head%N].t<=0)an+=min(a,q),cout<<s[Q[head%N].id]<<' '<<an<<endl;
    else Q[tail++%N]=Q[head%N],an+=q;
    head++;
  }
  return 0;
}