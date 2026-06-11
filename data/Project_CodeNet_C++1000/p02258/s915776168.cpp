#include <iostream>
  
int main(){
  
  int n;
  while(std::cin >> n){ 
    int *array = new int[n];
    for(int i = 0; i < n;i++){
      std::cin >> array[i];
    }
    int maxv = array[1] - array[0];
    int minj;
    if(maxv < 0){
      minj = array[1];
    }else{
      minj = array[0];
    }
    for(int j = 2; j < n;j++){
      if(minj > array[j-1]){
	minj = array[j-1];
      }
      if(maxv < array[j] - minj){
	maxv = array[j] - minj;
      }
    }
    std::cout << maxv << std::endl;
    delete[] array;
  }
  return 0;
}