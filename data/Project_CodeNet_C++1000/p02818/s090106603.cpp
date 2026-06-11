#include<bits/stdc++.h>
using namespace std;

int main(){
  long long A,B,K;
  cin >> A >> B >> K;
  cout << max(0LL,A-K);
  K=max(K-A,0LL);
  cout << " " << max(0LL,B-K) << endl;
}