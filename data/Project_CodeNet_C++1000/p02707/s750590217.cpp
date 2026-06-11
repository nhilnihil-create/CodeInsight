#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,num;
  cin >>N;
  vector<int> boss(N);
  vector<int> buka(N);
  for(int i=1;i<N;i++){
    cin >> boss.at(i);
    num=boss.at(i);
    buka.at(num-1)++;
  }
  for(int i=0;i<N;i++){
	cout << buka.at(i) << endl;
  }
}
