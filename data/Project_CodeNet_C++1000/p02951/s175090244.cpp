#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C;
  cin>>A>>B>>C;
  C -= A-B;
  cout<<(C>0? C: 0)<<endl;
}