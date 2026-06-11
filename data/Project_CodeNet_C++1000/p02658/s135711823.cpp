#include <bits/stdc++.h>
 using namespace std;

int main(){
  int N,i;
  long long m,l,t;
  t = 1e18;
  cin >> N;
  vector<long long> a(N);
  m = 1;
  for(i=0;i<N;i++)
    cin >> a[i];
  sort(a.begin(),a.end());
  for(i=0;i<N;i++){
    if (a[i] == 0){
      m = 0;
      break;
    }
    if (m > t/a[i]){
      m = -1;
      break;
    }
    m *= a[i];
  }
  cout << m << endl;
}