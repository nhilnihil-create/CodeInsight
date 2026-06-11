#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N;
  long long M=0;
  cin>>N;
  for(int X=1;X<N;X++){
    M+=X;
  }
  cout<<M<<endl;
}