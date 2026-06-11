#include <bits/stdc++.h>
#define Int int64_t
#define pb push_back
using namespace std;

int main()
{
  Int N;cin>>N;
  vector<Int> A(N);
  set<Int> s;
  for(auto &x:A) cin>>x,s.insert(x);
  
  Int largest=-1;int find=1;bool found=false;
  int i=0,j=0;
  while(i<N){
      if(A[i]==find){
          ++find;
          found=true;
      }
      i++;
  }
  cout<<(!found ? -1:N-find+1)<<"\n";
  
  
   
   
}