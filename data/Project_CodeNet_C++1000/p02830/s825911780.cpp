#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;

int main(){
  int i,N;
  cin>>N;
  string S,T;
  cin>>S>>T;
  i=0;
  while(i<N){
    cout<<S[i]<<T[i];
    i++;
  }
  cout<<endl;
}
