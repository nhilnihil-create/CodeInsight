#include<bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  int sum = 0;
  vector<int> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
    sum += vec.at(i);
  }
  vector<int> div(0);
  //約数列挙
  for(int n=1; n*n<=sum; n++){
    if(sum %n == 0){
      div.push_back(n);
      if(sum /n != n){
        div.push_back(sum /n);
      }
    }
  }
  sort(div.rbegin(),div.rend());
  for(int i=0; i<div.size(); i++){
    bool flag = true;
    vector<int> amari(0);
    int sum_a = 0;
    int d = div.at(i);
    for(int j=0; j<N; j++){
      if(vec.at(j) %d == 0){
        continue;
      }
      else{
        amari.push_back(vec.at(j) % d);
        sum_a += vec.at(j) % d;
      }
    }
    if(sum_a %d != 0){
      flag = false;
    }
    else{
      int x = sum_a / d;
      int cnt = 0;
      sort(amari.rbegin(),amari.rend());
      for(int j=0; j<x; j++){
        cnt += amari.at(j);
      }
      if(sum_a - cnt > K){
        flag = false;
      }
    }
    if(flag){
      cout << d << endl;
      break;
    }
  }
}