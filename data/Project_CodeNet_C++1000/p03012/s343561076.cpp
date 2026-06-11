#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,sum=0;
  cin >> N;
  vector<int> W(N);
  for(int i=0;i<N;i++){
    cin >> W.at(i);
    sum+=W.at(i);
  }
  int minA=10000;
  int sumB=0;
  for(int i=0;i<N;i++){
    sumB+=W.at(i);
    minA=min(minA,abs(sum-sumB-sumB));
  }
  cout << minA << endl;
}