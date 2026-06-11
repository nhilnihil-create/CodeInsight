#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int S=1;
  cin>>N;
  vector<int>vec(N);
  for(int X=0;X<N;X++){
    cin>>vec[X];
    if(vec[X]==S){
      S++;
    }
  }
  if(S==1){
    cout<<-1<<endl;
  }
  else{
    cout<<N-(S-1)<<endl;
  }
}