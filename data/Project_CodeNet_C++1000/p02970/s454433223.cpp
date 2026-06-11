#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){ 
  int N,D;
  cin >> N >> D;
  
  if(N % (2*D +1) == 0) cout << N / (2*D +1) << endl;
  else cout << N / (2*D +1) + 1 << endl;
}
