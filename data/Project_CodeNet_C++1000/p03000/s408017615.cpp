#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,x;cin>>N>>x;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  int d=0,num=1;
  for(int i=1;i<N+1;i++){
    d=d+a[i-1];
    if(d<=x){
      num++;
    }
  }

  cout<<num<<endl;
  return 0;
}
