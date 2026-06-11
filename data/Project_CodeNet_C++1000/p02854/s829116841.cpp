#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int64_t L=0;
  vector<int64_t> S(N);
  for(int i=0; i<N; i++){
    cin >> S.at(i);
    L+=S.at(i);
  }
  int64_t Now=0;
  int64_t Dif=4200000000;
  for(int i=0; i<N; i++){
    Now+=S.at(i);
    Dif=min(Dif, abs(2*Now-L));
  }
  cout << Dif << endl;
}
    