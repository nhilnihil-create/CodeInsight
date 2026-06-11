#include <bits/stdc++.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  int X, N, p;
  vector<int> list;
  cin >> X >> N;
  
  for (int i = 0; i < N; i++){
    cin >> p;
    list.push_back(p);
  }
  list.push_back(10100);
  for (int j = 0; j <= N + 1; j++){
    
    vector<int>::iterator itl = find(list.begin(), list.end(), X - j);
    vector<int>::iterator itp = find(list.begin(), list.end(), X + j);
    
    if (itl == list.end()){
      cout << X - j << endl;
      j = N + 2;
    }  else if (itp == list.end()){
      cout << X + j << endl;
      j = N + 2;
    }

  }   
}