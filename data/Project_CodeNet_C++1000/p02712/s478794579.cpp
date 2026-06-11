#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  double sum = 0;
  int a[N];
  for(int i=0;i<N;i++){
    a[i]=i+1;
    if(a[i]%3!=0&&a[i]%5!=0){
      sum += a[i];
    }
  }
  cout << static_cast<long long int>(sum)<< endl;
  return 0;
}