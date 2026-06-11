#include<iostream>
using namespace std;

int main(){
  int i = 0, n, a;
  long min = 1000000, max = -1000000, total = 0;

  cin >> n;

  while(i < n){
    cin >> a;

    if (min > a) min = a;
    if (max < a) max = a;
    total += a;
    i++;
  }
  cout << min << " " << max << " " << total << endl;

  return 0;
}