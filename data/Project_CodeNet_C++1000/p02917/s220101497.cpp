#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  long long H=0;
  cin>>N;
  vector<int>vec(N);
  for(int X=0;X<N-1;X++){
    cin>>vec[X];
    if(X>0){
      H+=min(vec[X],vec[X-1]);
    }
  }
  cout<<H+vec[0]+vec[N-2]<<endl;
}