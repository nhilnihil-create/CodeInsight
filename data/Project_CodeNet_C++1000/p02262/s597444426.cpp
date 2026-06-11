#include <iostream>

using namespace std;

class sorter{
  int cnt;
public:
  void shellSort(int *array, int num);
private:
  void insertionSort(int *array, int num, int g);
};

void sorter::insertionSort(int *array,int num, int g){
  for (int i = g; i < num; i++) {
    int v = array[i];
    int j = i -  g;
    while (j >= 0 && array[j] > v) {
      array[j + g] = array[j];
      j -= g;
      cnt++;
    }
    array[j + g] = v;
  }
}

void sorter::shellSort(int *array, int num){
  int h = 1;
  int m = 0;

  for (int h_tmp = 1; h_tmp < num/* "/ 9" */; h_tmp = h_tmp * 3 + 1){
    h = h_tmp;
    m++;
  }
  if (h == 1) m = 1;
  cout /*<< "m = "*/ << m << endl;
  for(int h_tmp = h; h_tmp > 0; h_tmp /= 3){
    cout /*<< "h_tmp = "*/ << h_tmp;
    if(h_tmp == 1){
      cout << endl;
    }else{
      cout << " ";
    }
  }
  cnt = 0;
  while( h > 0){
    insertionSort(array, num, h);
    h /= 3;
  }
  cout /*<< "cnt = "*/ << cnt << endl;
}


int main(int argc, char const *argv[]) {
  int num;
  cin >> num;
  int *array = new int[num];
  for(int i = 0; i < num; i++){
    cin >> array[i];
  }
  sorter s;
  s.shellSort(array, num);
  for(int i = 0; i < num; i++){
    cout << array[i] << endl;
  }
  delete [] array;
  return 0;
}