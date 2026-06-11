#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
  int N;  cin >> N;
  vector<int>W(N);
  for(int i=0;i<N;i++){
    cin >> W.at(i);
  }
  int S1 = 0;
  int S2 = 0;
  for(int i=0;i<N;i++){
    S2 += W.at(i);
  }
  int min = 100000;
  for(int i=0;i<N-1;i++){
    S1 += W.at(i);
    S2 -= W.at(i);
    if(min > abs(S1-S2))  min = abs(S1-S2);
  }
  cout << min << endl;
}
