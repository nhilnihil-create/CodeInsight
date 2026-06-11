#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0; i < n; ++i)
    cin >> A[i];

  auto ok = [&](){
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        vector<int> B = A;
        swap(B[i],B[j]);
        bool f = true;
        for(int k = 0; k < n; ++k){
          if(B[k] != k+1){
            f = false;
            break;
          }
        }
        if(f){
          return true;
        }
      }
    }
    return false;
  };

  if(ok()) puts("YES");
  else puts("NO");
}
