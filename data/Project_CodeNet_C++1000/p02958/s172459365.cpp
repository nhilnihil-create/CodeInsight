#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int>A(N);
  int cnt=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    if(i+1!=A[i])cnt++;
  }
  if(cnt==2||cnt==0){
    cout<<"YES"<<endl;
    return 0;
  }
  cout<<"NO"<<endl;

}