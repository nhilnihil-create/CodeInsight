#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N,money,kabu;
  cin >> N;
  money = 1000;
  kabu=0;
  vector<long long>data(N);
  for (int i=0; i<N; i++) {
    cin >> data.at(i);
  }
  for(int i=0; i<N-1; i++) {
    if (data.at(i) < data.at(i+1)){
      money = money + (((data.at(i+1) - data.at(i)) * (money / data.at(i))));
    }
  }
                        
  cout << money << endl;
}
  
