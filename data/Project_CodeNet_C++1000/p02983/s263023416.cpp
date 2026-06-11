#include <bits/stdc++.h>
using namespace std;


int main() {

  int64_t L,R;
  cin>>L>>R;

  int64_t min_wk=2020;
  if(R-L>=2020)
    cout<<0<<endl;
  else{
    for(int64_t i=L;i<R;i++){
      for(int64_t j=i+1;j<=R;j++)
        min_wk = min(min_wk,(j*i)%2019);
    }
    cout<<min_wk<<endl;
  }

  return 0;
}

