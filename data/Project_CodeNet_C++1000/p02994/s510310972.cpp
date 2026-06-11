#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,i,M;
  cin >> a >> b;
  vector<int> vec(a);
  for(i=0;i<a;i++)vec[i]=b+i;
  M = 1000;
  int t=0;
  for(i=0;i<a;i++)if (M > abs(vec[i])) t = vec[i],M=abs(vec[i]);
  int S = accumulate(vec.begin(),vec.end(),0);

  cout << S - t << endl;
  
  
}