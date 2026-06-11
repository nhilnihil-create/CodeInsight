#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,a;
  cin>>N;
  vector<int> S(N+1);
  for(int i=1; i<=N-1; i++){
    cin>>a;
    S.at(a)++;
  }
  for(int i=1; i<=N; i++){
    cout<<S.at(i)<<endl;
  }
}
  