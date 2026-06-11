#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M=1;
  cin>>N;
  for(int i=0;i<N;i++){
    M*=2;
  }
  vector<int> p(M);
  for(int i=0;i<M;i++){
    cin>>p[i];
  }
  sort(p.begin(),p.end());
  reverse(p.begin(),p.end());
  vector<int> seen(M);
  seen[0]=1;
  vector<int> q;
  q.push_back(p[0]);
  int L=1,Z=1;
  for(int i=0;i<N;i++){
    int A=0,B=0;
    while(A<M&&B<L){
      if(seen[A]==0&&q[B]>p[A]){
        q.push_back(p[A]);
        seen[A]=1;
        B+=1;
      }
      A++;
    }
    if(B==L){
      L*=2;
      sort(q.begin(),q.end());
      reverse(q.begin(),q.end());
    }
    else{
      Z=0;
      break;
    }
  }
  if(Z){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}