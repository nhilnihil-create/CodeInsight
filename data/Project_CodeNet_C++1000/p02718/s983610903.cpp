#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,j=0;
  cin>>N>>M;
  vector<int> A(N);
  for(int &i:A){
    cin>>i;
    j+=i;
  }
  sort(A.begin(),A.end());
  if(A[N-M]*4*M<j)
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
}
