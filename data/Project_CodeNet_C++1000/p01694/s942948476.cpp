#include <iostream>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(){
  int n;
  string foot;
  int left = 0;
  int right = 0;
  int status = 0;
  int count = 0;
  while(1){
    count = 0;
    int left = 0;
    int right = 0;
    int status = 0;
    cin >> n;
    if(n == 0){
      break;
    }

    for(int i = 0;i < n;i++){
      cin >> foot;
      if(foot == "lu"){
        left = 1;
      }else if(foot == "ru"){
        right = 1;
      }else if(foot == "ld"){
        left = 0;
      }else{
        right = 0;
      }
      

      if(left == 1 && right == 1 && status == 0){
        count++;
        status = 1;
      }

      if(left == 0 && right == 0 && status == 1){
        count++;
        status = 0;
      }
    }
    cout << count << endl;
  }
}