#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  vector<int> P(N),Q(N);
  for(int i=0;i<N;i++) cin>>P.at(i);
  for(int i=0;i<N;i++) cin>>Q.at(i);
  vector<int> v;
  for(int i=1;i<=N;i++) v.push_back(i);
  vector<vector<int>> D;
  do {
   D.push_back(v);
} while (next_permutation(v.begin(), v.end()));
  
  int Ln=D.size();
  int X=0;
  int Y=0;
  for(int i=0;i<Ln;i++){
    if(D[i]<P) X++;
  }
  for(int i=0;i<Ln;i++){
    if(D[i]<Q) Y++;
  }
  if(X>Y) cout<<X-Y<<endl;
  else cout<<Y-X<<endl;
}


