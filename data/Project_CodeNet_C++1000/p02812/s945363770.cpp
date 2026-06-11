#include<iostream>
#include<string>
int main(void){
  int N;
  std::string S;
  std::cin >> N >> S;
  int count = 0;
  for (int i=0;i<N-2;i++){
    int b = 0;
    for (int j=0;j<3;j++){
      if (S.at(i+j) == 65+j) b++;
    }
    if (b==3) count++;
  }
  std::cout << count << std::endl;
  return 0;
}