#include <bits/stdc++.h>
using namespace std;
using vv=vector<int>;

int main(){
  long i,N=1,M,A,B;
  cin>>A>>B;
  M=min(A,B);
  for(i=2;i<M+1;i++){
    if(A%i==0&&B%i==0)N=i;
  }
  cout<<A*B/N<<endl;
}
