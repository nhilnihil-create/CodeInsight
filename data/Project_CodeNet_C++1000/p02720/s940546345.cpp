#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
  deque<long long> L;
  rep(i,9)
    L.push_back(i+1);
  
  int K;
  cin >> K;
  
  long long a;
  int b;
  rep(i,K-1){
    a = L.front();
    L.pop_front();
    b = a%10;
    if (b != 0)
      L.push_back(a*10+b-1);
    L.push_back(a*10+b);
    if (b != 9)
      L.push_back(a*10+b+1);
  }
  cout << L.front() << endl;
}