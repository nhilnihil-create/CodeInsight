#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> P(N),Q(N);
  for(int i=0;i<N;i++){
    cin>>P.at(i);
  }
  for(int i=0;i<N;i++){
    cin>>Q.at(i);
  }
  vector<int> perm = P;
  int p_num=0,q_num=0;
  int i=1;
  sort(perm.begin(),perm.end());
  do{
    if(perm==P)
      p_num=i;
    if(perm==Q)
      q_num=i;
    i++;
  }while(next_permutation(perm.begin(),perm.end()));
  
  cout<<abs(p_num-q_num)<<endl;
}
