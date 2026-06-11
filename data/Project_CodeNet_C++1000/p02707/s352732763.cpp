#include <iostream>
using namespace std;

long array[200000];

int main() {
  int N;
  cin >> N;
  for (int i = 1; i < N; i++){
    int l;
    cin >> l;
    array[l-1]++;
  }
  for (int i = 0; i < N; i++){
    cout << array[i] << endl;
  }
  return 0;
}