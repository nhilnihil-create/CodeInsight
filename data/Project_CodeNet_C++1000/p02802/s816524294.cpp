#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N,M;
  cin >> N >> M;
  vector<bool> over(N,false);
  vector<int> WA(N,0);
  for(int i=0;i<M;i++){
    int p;
    string S;
    cin >> p >> S;
    --p;
    if(over[p]){
      continue;
    }
    if(S=="AC"){
      over[p]=true;
    }
    else{
      WA[p]++;
    }
  }
  int ACans=0,WAans=0;
  for(int i=0;i<N;i++){
    if(over[i]){
      ACans++;
      WAans+=WA[i];
    }
  }
  cout << ACans << " " << WAans << endl;
}