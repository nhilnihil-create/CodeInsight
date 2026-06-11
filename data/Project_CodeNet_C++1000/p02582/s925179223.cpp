#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int n = S.size();
  int cmax,max;
  cmax = 0;
  max = 0;
  for(int i = 0;i < n;i++){
    if(S.at(i) == 'R')cmax++;
    if(S.at(i) == 'S')cmax = 0;
    if(cmax > max)max = cmax;
  }
  cout << max;

}