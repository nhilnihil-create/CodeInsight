#include <iostream>
#include <cstring>
using namespace std;

int p[250000];

int main() {
  memset(p, 0, sizeof(p));
  for(int i=4; i<250000; i+=2) p[i] = 1;
  for(int i=3; i*i<250000; i+=2)
    if(p[i] == 0)
      for(int j=2; i*j<250000; ++j)
        p[i*j] = 1;

  int n;
  while(cin>>n, n) {
    int cnt = 0;
    for(int i=n+1; i<=2*n; ++i)
      if(p[i] == 0) cnt++;
    cout<<cnt<<endl;
  }
}