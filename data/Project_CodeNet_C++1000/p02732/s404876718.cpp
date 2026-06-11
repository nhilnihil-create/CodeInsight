#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<long long>a(N);
  vector<long long>b(N,0);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
    b.at(a.at(i)-1)++;
  }
  
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    sum += b.at(i)*(b.at(i)-1)/2;
  }
  for (int i = 0; i < N; i++) {
    if (b.at(a.at(i)-1) > 0){
      cout << sum - b.at(a.at(i)-1)*(b.at(a.at(i)-1)-1)/2 + (b.at(a.at(i)-1)-2)*(b.at(a.at(i)-1)-1)/2 << endl;
    }
    else {
      cout << sum - b.at(a.at(i)-1)*(b.at(a.at(i)-1)-1)/2 << endl;
    }
  }
}
    
   