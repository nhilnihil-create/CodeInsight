#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
   cin >> N ;
  int i;
  int j;
  vector<int> X(N);
 
  for (i=0;i<N;i++){
  cin >>X.at(i);
   //cout << i << endl; 
   //  cout << X.at(i) << endl; 
  }
  int P;
  P =0;
  int answer;
  answer =0;
  int plus;
  plus =0;
   for (i=0;i<N;i++) {
    // cout << i << endl; 
   plus = X.at(i)*X.at(i);
     //cout << plus << endl; 
     answer = answer + plus;
  }
  plus = 0;
  for(j=1;j<100;j++){
  for (i=0;i<N;i++) {
    plus =plus+(X.at(i)-j)*(X.at(i)-j);
  }
    answer=min(answer,plus);
    plus =0;
  }
  
  P =answer;
  cout << P << endl; 
}