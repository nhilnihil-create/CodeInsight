#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,Vmax;
  cin >> N >> Vmax;

  vector<int64_t> data(N);
  int64_t buf;
  for(int i=0; i<N; i++){
    cin >> buf;
    buf/= 2;
    
    data.at(i)= buf;
  }

  int64_t cumlcd= 1;
  int ord2= 0;
  bool possible= true;
  for(int i=0; i<N; i++){
    int cnt= 0;
    int64_t div= 2;
    while(data.at(i)% div==0){
      cnt++;
      div*= 2;
    }
    if(i==0){ ord2= cnt; }
    else if(ord2 != cnt){
      possible= false;
      break;
    }

    cumlcd= lcm(cumlcd, data.at(i));
    if(cumlcd > Vmax){
      possible= false;
      break;
    }
  }

  int64_t ans= possible ? ((Vmax/cumlcd)+ 1)/ 2
                        : 0;
  
  cout << ans << endl;
}