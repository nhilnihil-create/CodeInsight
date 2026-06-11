#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,Q;
  long long K;
  cin>>N>>K>>Q;
  vector<int>vec(Q);
  vector<long long>v(N,K-Q);
  for(int X=0;X<Q;X++){
    cin>>vec.at(X);
    v.at(vec.at(X)-1)++;
  }
  for(int X=0;X<N;X++){
    if(v.at(X)>0){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
}