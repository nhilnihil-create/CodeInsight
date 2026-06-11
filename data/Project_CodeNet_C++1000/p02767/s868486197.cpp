#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> data(N);
  for(int i=0;i<N;i++)
    cin >> data.at(i);
  int p=0;
  for(int i=0;i<N;i++)
    p += data.at(i);
  
  if(p % N == 0){
    p /= N;
  }
  else if( (double)(p%N)/N <= 0.5 ){
    p = (p-(p%N)) / N;
  }
  else {
    p = ( (p-(p%N)) / N ) + 1; 
  }
  
  int answer=0;
  for(int i=0;i<N;i++)
    answer += ((data.at(i) - p)*(data.at(i) - p))  ;
  cout << answer;
  
}