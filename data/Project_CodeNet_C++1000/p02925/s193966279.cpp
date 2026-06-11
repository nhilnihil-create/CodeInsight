#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<vector<int>> vec(N,vector<int>(N-1));
  for(int i=0; i<N; i++){
    for(int j=0; j<N-1; j++){
      cin >> vec.at(i).at(j);
    }
  }
  
  vector<vector<int>> day(N,vector<int>(N-1,-1));
  vector<int> nex(N,0);
  vector<int> over(N,-1);
  queue<int> Q;
  for(int i=0; i<N; i++){
    int a = vec.at(i).at(0);
    if(vec.at(a-1).at(0) == i+1){
      Q.push(i);
      nex.at(i)++;
      over.at(i)++;
      day.at(i).at(0) = 1;
    }
  }
 
  
  while(Q.size()){
    int x = Q.front();
    Q.pop();
    if(over.at(x) > 0){
      over.at(x)--;
      continue;
    }
    int y = nex.at(x);
    int z = vec.at(x).at(y); //次の対戦相手
    z--;
    if(vec.at(z).at(nex.at(z)) == x+1){
      if(nex.at(z) == 0){
        day.at(x).at(nex.at(x)) = day.at(x).at(nex.at(x)-1) + 1;
        day.at(z).at(nex.at(z)) = day.at(x).at(nex.at(x)-1) + 1;
      }
      else{
        day.at(x).at(nex.at(x)) = max(day.at(x).at(nex.at(x)-1),day.at(z).at(nex.at(z)-1)) + 1;
        day.at(z).at(nex.at(z)) = max(day.at(x).at(nex.at(x)-1),day.at(z).at(nex.at(z)-1)) + 1;
      } 
      nex.at(x)++;
      nex.at(z)++;
      if(nex.at(x) < N-1){
        Q.push(x);
      }
      if(nex.at(z) < N-1){
        Q.push(z);
      }
      over.at(z)++;
    }
    else{
      over.at(x) = -1;
    }
  }
  
  /*for(int i=0; i<N; i++){
    for(int j=0; j<N-1; j++){
      cout << day.at(i).at(j);
    }
    cout << endl;
  }*/
  
  int ans = 0;
  for(int i=0; i<N; i++){
    for(int j=0; j<N-1; j++){
      if(day.at(i).at(j) == -1){
        ans = -1;
        break;
      }
      ans = max(ans,day.at(i).at(j));
    }
    if(ans == -1){
      break;
    }
  } 
  cout << ans << endl; 
}

