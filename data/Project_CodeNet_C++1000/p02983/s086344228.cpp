#include <bits/stdc++.h>
using namespace std;

int main(){

  long long L,R;
  cin >> L >> R;

  long long i = L;
  long long j = L+1;
  int min = 2018;
  int now;
  while(i < j && i <= L +2019){
    j = i+1;
  
    while(j <= R && j <= L +2019){
      now = ((i%2019) * (j % 2019)) % 2019;
      if(now < min) min = now;
      j++;
    }
    i++;
  }

  cout << min << endl;
}
