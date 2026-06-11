#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin>>N;

  int X;
  priority_queue<int> A;
  for(int i=0;i<N;i++){
    cin>>X;
    A.push(X);
  }
 for(int i=0;i<(N/2)-1;i++){
   A.pop();
 }
 int B,C;
 B=A.top();
 A.pop();
 C=A.top();
 cout<<B-C;
}

    
  
  
