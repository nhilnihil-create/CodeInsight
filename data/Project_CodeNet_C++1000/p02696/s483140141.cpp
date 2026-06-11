#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  long long A,B,N;
  cin>>A>>B>>N;
  
  long long x=min(B-1,N);
  
  cout<<A*x/B<<endl;
}