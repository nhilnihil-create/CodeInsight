  
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
  int a, b, c=0;
  int N;
  cin >> N;
  vector<int> p(N), q(N), v(N);
  for(int i=0; i<N;i++){
    cin >> p[i];
    v[i] = i+1;
  }
  for(int i=0; i<N; i++) cin >> q[i];
  do{
    c++;
    if(p==v) a = c;
    if(q==v) b = c;
  }while(next_permutation(v.begin(), v.end()));
  cout << abs(a-b) << endl;
  return 0;
}