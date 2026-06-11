#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin>>N>>M;
  vector<int> a(N);
  int x;
  int sum = 0;
  for(int i=0; i<N; i++){
    cin>>x;
    a.at(i)=x;
    sum+=x;
  }
  int b;
  if(sum%(4*M) == 0) b = sum/(4*M);
  else b = sum/(4*M)+1;
  
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  if(a.at(M-1)>=b) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}