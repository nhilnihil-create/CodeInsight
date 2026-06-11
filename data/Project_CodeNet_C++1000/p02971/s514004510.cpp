#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int a1=0,a2=0,b1;
  for(int i=0;i<N;i++){
    int A;
    cin>>A;
    if(A>a1)
      a2=a1,b1=i,a1=A;
    else if(A>a2)
      a2=A;
  }
  for(int i=0;i<N;i++){
    if(i==b1)
      cout<<a2<<endl;
    else
      cout<<a1<<endl;
  }
}