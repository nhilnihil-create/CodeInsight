#include <iostream>
#include <string>

static int e = 0;

void quickSort(std::string c, int start, int size){
  int i=start,j=start+size-1;
  while(i<j){
    if(c[i] == 'W' && c[j] == 'R'){
      c[i] = 'R';
      c[j] = 'W';
      e++;
    }else{
      if(c[i] != 'W') i++;
      if(c[j] != 'R') j--;
    }
  }
}

int main(){
  int n;
  std::string c;
  std::cin >> n;
  std::cin >> c;
  
  quickSort(c, 0, n);
  std::cout << e << std::endl;
}


