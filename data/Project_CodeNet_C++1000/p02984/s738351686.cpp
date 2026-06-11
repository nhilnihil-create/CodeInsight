#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  int64_t a=0;
  for(int i=0;i<N;i++){
  if(i%2==0)
    a+=A.at(i);
    else
      a-=A.at(i);
  }a/=2;
  vector<int64_t>B(N);
  B.at(0)=a;
  for(int i=1;i<N;i++)
    B.at(i)=A.at(i-1)-B.at(i-1);
  for(int i=0;i<N-1;i++)
    cout<<2*B.at(i)<<" ";
  cout<<2*B.at(N-1)<<endl;
    return 0;
}