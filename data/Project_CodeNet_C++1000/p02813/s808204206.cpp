#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

  int n, a = 0, b = 0;
  char popo;
  cin >> n;
  string buff1, buff2, buffest;
  for(int i = 1;i <= n;i++){
    buffest.push_back('0' + i);
  }
  for(int i = 1;i <= n;i++){
    cin >> popo;
    buff1.push_back(popo);
  }
  for(int i = 1;i <= n;i++){
    cin >> popo;
    buff2.push_back(popo);
  }
  int i = 0;
  while(next_permutation(buffest.begin(), buffest.end()) && (a == 0 || b == 0)){
    i++;
    if(buff1 == buffest){
      a = i;
    }
    if(buff2 == buffest){
      b = i;
    }
  }
  cout << abs(a - b);
}
