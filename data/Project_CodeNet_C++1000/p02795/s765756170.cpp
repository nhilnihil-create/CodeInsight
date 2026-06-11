#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W,N;
  cin>>H>>W>>N;
  int A=N/H;
  int B=N/W;
  
  if(H>=W){
    if(A*H==N){
      cout<<A<< endl;
    }
    else{
      cout<<A+1<< endl;
    }
  }
  if(H<W){
    if(B*W==N){
      cout<<B<< endl;
    }
    else{
      cout<<B+1<< endl;
    }
  }
}