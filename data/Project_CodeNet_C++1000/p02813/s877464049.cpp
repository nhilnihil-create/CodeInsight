#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> P(N),Q(N),R(N);
  for(int i=0;i<N;i++){
    cin >> P[i];
  }
  for(int i=0;i<N;i++){
    cin >> Q[i];
  }
  for(int i=0;i<N;i++){
    R[i] = i+1;
  }
  int p,q,i=0;
  do{
    if(R==P){
      p =i;
    }
    if(R==Q){
      q=i;
    }
    i++;
  }while(next_permutation(R.begin(),R.end()));
  cout << abs(p-q) << endl;
}
