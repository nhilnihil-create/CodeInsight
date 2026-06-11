#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
const long long INF = 1LL << 60;

int main() {
  int N;
  cin>>N;
  int bar[N];
  long long all=0; //全部の和
  for(int i=0; i<N; i++){
    cin>>bar[i];
    all+=bar[i];
  }
  long long min=INF;
  int kiru=0;
  long long zenhan=0;
  for(int i=0; i<N; i++){
    zenhan+=bar[i];
    if(abs(all-2*zenhan)<min){
      min=abs(all-2*zenhan);
      kiru=i; //i番目で切ると差が最小
  } //if
  } //i
  cout<<min<<endl;
  // cout<<kiru<<endl;
}