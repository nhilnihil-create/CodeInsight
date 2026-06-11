#include <iostream>
using namespace std;
int main(void){
    int N, K;
    cin >> N >> K;
  if(K == 1){
    cout << "0" << endl;
    return 0;
  }
    int n = N - K;
    cout << n << endl;
}