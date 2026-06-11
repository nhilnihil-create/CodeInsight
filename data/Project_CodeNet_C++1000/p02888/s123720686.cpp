#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;vector<int>L(N);long long J=0;
  for(int X=0;X<N;X++){
    cin>>L[X];
  }
  sort(L.begin(),L.end());
  for(int X=0;X<N-2;X++){
    for(int Y=X+1;Y<N-1;Y++){
      for(int Z=Y+1;Z<N;Z++){
        if(L[X]+L[Y]>L[Z])J++;
        else break;
      }
    }
  }
  cout<<J<<endl;
}