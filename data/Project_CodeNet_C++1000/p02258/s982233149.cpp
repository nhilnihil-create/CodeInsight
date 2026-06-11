#include <iostream>
using namespace std;

int main(){

  int size, max, sa;

  cin >> size;

  int *array = new int[size];

  for(int i = 0; i < size; i++){
    cin >> array[i];
  }

  max = -2000000000;

  int minv = array[0];

  for(int i = 1; i < size; i++){
    if(max < array[i] - minv){
      max = array[i] - minv;
    }
    if(minv > array[i]){
      minv = array[i];
    }

  }

  cout << max << "\n";


  delete[] array;
  return 0;
}
