#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> H(N);
  for(int i=0;i<N;i++){
    cin >> H.at(i);
  }
  vector<vector<int>> G(N);
  for(int i=0;i<M;i++){
    int A,B;
    cin >> A >> B;
    G.at(A-1).push_back(B-1);
    G.at(B-1).push_back(A-1);
  }
  int count=0;
  for(int i=0;i<N;i++){
    if(G.at(i).size()==0){
      count++;
    }
    else{
      bool a=true;
      for(int b:G.at(i)){
        if(H.at(i)<=H.at(b)){
          a=false;
        }
      }
      if(a){
        count++;
      }
    }
  }
  cout << count << endl;
}
        