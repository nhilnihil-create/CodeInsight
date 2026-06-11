#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int N,count=0;
  cin>>N;
  vector<int> p(N);
  vector<int> fuga(N);
  for(int i=0; i<N; i++){
    cin>>p[i];
    fuga[i]=p[i];
  }
  sort(p.begin(),p.end());
  for(int i=0; i<N; i++){
    if(p[i]!=fuga[i]){
      count++;
    }
  }
  cout<<(count<=2?"YES":"NO");
}
      