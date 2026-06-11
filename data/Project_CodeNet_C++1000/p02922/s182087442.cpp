#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin>>A>>B;
  int i=0;
  int C=1;
  while(B>C){
      C+=A-1;
    i++;
  }
  cout<<i<<endl;
}
