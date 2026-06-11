#include<iostream>
using namespace std;

int main(){
  int N,X;  cin >> N >> X;
  int x = 0;
  int ans;
  for(int i=0;i<N;i++){
    int L;  cin >> L;
    x += L;
    if(x > X){
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << N+1 << endl;
}
