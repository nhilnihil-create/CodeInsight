#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;cin>>N;
  vector<int> a(N+1),b(N+1,0),c(N+1,0);
  for(int i=1;i<=N;i++){
    cin>>a[i];
  }
  int M=0;
  for(int i=N;i>=1;i--){
    if(a[i]^(c[i]&1)){
      b[i]=1;
      M++;
      for(int j=1;j*j<=i;j++){
        if(i%j==0){
          c[j]++;
          if(j!=i/j) c[i/j]++;
        }
      }
    }
  }
  cout<<M<<endl;
  for(int i=1;i<=N;i++){
    if(b[i]) cout<<i<<' ';
  }
  cout<<endl;
  return 0;
}