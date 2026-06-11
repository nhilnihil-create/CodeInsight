#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<pair<int,int>> p(N);
  for(int i=0;i<N;i++){
    int a,b;
    cin>>a>>b;
    p[i]=make_pair(b,a);
  }
  sort(p.begin(),p.end());
  int T=0,Z=1;
  for(int i=0;i<N;i++){
    int a,b;
    tie(b,a)=p[i];
    T+=a;
    if(b<T){
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

