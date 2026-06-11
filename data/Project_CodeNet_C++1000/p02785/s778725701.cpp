#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,K;
  long long S=0;
  cin>>N>>K;
  vector<long long>vec(N);
  for(long long X=0;X<N;X++){
    cin>>vec.at(X);
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  if (N<=K){
    cout<<0<<endl;
  }
  else{
    for(long long X=K;X<N;X++){
      S+=vec.at(X);
    }
    cout<<S<<endl;
  }
}