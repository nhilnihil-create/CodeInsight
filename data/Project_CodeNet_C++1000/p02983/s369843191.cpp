#include<bits/stdc++.h>
using namespace std;
int main(){
  long long L, R, Min=2019, i, j;
  cin >> L >> R;
  R = min(R, L + 2019);
  for(i=L;i<=R;i++){
    for(j=i+1;j<=R;j++){
      long long i_=i%2019, j_=j%2019;
        Min = min(Min, (i_*j_)%2019);
    }
  }
  cout << Min << endl;
  return 0;
}