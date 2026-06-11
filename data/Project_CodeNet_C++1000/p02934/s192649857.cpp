#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){    
  int N,A;
  cin >> N;
  double a = 0;
  for(int i = 0; i < N; i++){
    cin >> A;
    a += (1.0/A)*100000;
  }
  cout <<  fixed << setprecision(8) << 100000/a << endl;
}
