#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int>A(N);
  for (int i=0; i<N; i++)cin>>A[i];
  int cnt=0;
  for(int i=0; i<N; i+=2){
    if(A[i]%2==1)cnt++;
  }
  cout<<cnt<<endl;
}
