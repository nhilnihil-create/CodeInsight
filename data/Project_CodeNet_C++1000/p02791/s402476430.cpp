#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,S=0,m=100000000;
  cin>>N;
  vector<int>v(N);
  for(int i=0;i<N;i++){
    cin>>v[i];
    if(m>v[i]){
      S++;
      m=v[i];
    }
  }
  cout<<S<<endl;
}