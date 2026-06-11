#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M; cin >> N >> M;
  int ac = 0,wa = 0;
  vector<int> wrong(N + 1,0);
  vector<bool> clear(N + 1,true);
  for(int i = 0; i < M; i++){
    int p;
    string S; cin >> p >> S;
    
    if(S == "AC"){
      if(clear.at(p)){
        clear.at(p) = false;
        ac++;
        wa += wrong.at(p);
      }
    }
    else{
      if(clear.at(p)) wrong.at(p)++;
    }
  }
  
  cout << ac << " " << wa << endl;      
}
      