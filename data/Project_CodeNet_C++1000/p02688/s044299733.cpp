#include <iostream>

using namespace std;

int main(void){
  int n, k, an[101] = {0}, d, a, i, j, count = 0;
  cin >> n >> k;
  for(i = 0; i < k; i++){
    cin >> a;
    for(j = 0; j < a; j++){
      cin >> d;
      an[d]++;
    }
  }
  for(i = 1; i <= n; i++){
    if(an[i] == 0){
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
  