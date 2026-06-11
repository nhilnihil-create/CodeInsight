#include<iostream>

using namespace std;

int main(){
  int x;
  int y;
  int z;
  int _N_MAX = 10050;
  
  int arr[_N_MAX] = {0};
    for(x = 1; x < 105; x++){
      for(y = 1; y < 105; y++){
        for(z = 1; z < 105; z++){
          if(x*x + y*y + z*z + x*y + y*z + z*x < _N_MAX){
            int v = x*x + y*y + z*z + x*y + y*z + z*x;
            arr[v]++;
          }
        }
      }
    }
  int N;
  cin >> N;
  for(int idx = 1; idx <= N; idx++){
    cout << arr[idx] << endl;
  }
}
