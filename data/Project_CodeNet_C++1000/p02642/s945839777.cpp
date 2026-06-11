#include <bits/stdc++.h>
 using namespace std;

int main(){
  int N;
  int i,j,k;
  cin >> N;
  int Amax = 1000001;
  vector<bool> s(Amax,false);
  vector<int> c(Amax,0);

  for(i=0;i<N;i++){
    cin >> j;
    c[j]++;
    s[j] = true;
  }

  for(i=0;i<Amax;i++){
    if (s[i] && (c[i] > 0))
      for(j=i*2;j<Amax;j+=i)
        s[j] = false;
    if (c[i] > 1)
      s[i] = false;
  }

  int ct = 0;
  for(i=0;i<Amax;i++)
    if (s[i])
      ct++;
  cout << ct << endl;
}