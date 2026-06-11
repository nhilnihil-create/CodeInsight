#include <bits/stdc++.h>
#include <iostream>
#include <numeric>
using namespace std;


int main() {
  int N;
  cin >> N;
  if(N % 2 == 1){
  cout << N / 2;
  }else{
  cout << N / 2 - 1;
  }
}