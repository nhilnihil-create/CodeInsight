#include <bits/stdc++.h>
using namespace std;

int fact(int x){
  int ans = 1;
  for(int i = 1; i <= x; i++){
    ans *= i;
  }
  return ans;
}


int main(){
  vector<string> al{"a","b","c","d","e","f","g","h","i","j"};
  
  int N;
  cin >> N;
  
  vector<string> ans(N);
  
  int maxi = fact(N);
  vector<vector<int>> list(maxi, vector<int>(N));
  vector<int> dels(0);
  
  for(int i = 0; i < N; i++){
    list.at(0).at(i) = 1;
  }

  for(int i = 1; i < maxi; i++){
    for(int j = 0; j < N-1; j++){
      list.at(i).at(0) = 1;
      list.at(i).at(N-1-j) = list.at(i-1).at(N-1-j);
      list.at(i).at(N-1) = list.at(i-1).at(N-1) + 1;
    }
    for(int k = N-1; k > 0; k--){
      if(list.at(i).at(k) == k+2){
        list.at(i).at(k) = 1;
        list.at(i).at(k-1) +=1;
      }  
    }
  }
  
  int big = 0;
  int dis = 0;
  
  for(int i = 0; i < maxi; i++){
    for(int j = 1; j < N; j++){
      big = max(list.at(i).at(j-1), big);
      dis = list.at(i).at(j) - big;
      
      if(dis > 1){
        list.at(i).at(0) = -1;
      }
    }
    big = 0;
  }
  
  for(int i = 0; i < maxi; i++){
    if(list.at(i).at(0) != -1){
      for(int j = 0; j < N; j++){
      	cout << al.at(list.at(i).at(j) - 1);
      }
     cout << endl;     
    }
  }

}