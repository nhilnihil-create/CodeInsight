#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,sum=0;
  cin >> N >> M;
  vector<int> day(M);
  for(int i=0;i<M;i++){
	cin >> day.at(i);
    sum+=day.at(i);
  }
  if(sum<=N){
    cout << N-sum;
  }else{
    cout << -1;
  }
}
