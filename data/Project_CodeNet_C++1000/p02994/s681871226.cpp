#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int N,L;  cin >> N >> L;
  int ans = 0;
  int min = abs(L);
  int mini;

  for(int i=0;i<N;i++){
    if(min >= abs(L+i)){
      min = abs(L+i);
      mini = L+i;
    }
    ans += L+i;
  }
  cout << ans - mini << endl;
}
