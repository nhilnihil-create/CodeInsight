#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C,D;
  cin>>A>>B>>C;
  D=min(A+B,min(B+C,C+A));
  cout<<D<<endl;
}
