#include <iostream>
#include <string>
using namespace std;

int draw(int H, int W, char* str, int count = 0);

int main() {

  int H, W;
  while(1){
    cin >> H >> W;
    
    if(H + W == 0) {
      break;
    }
    char str[W];
    str[0] = '.';
    for(int i = 1; i < W; i++){
      if(str[i - 1] == '.') str[i] = '#';
      else str[i] = '.';
    }

    draw(H, W, str);
    cout << endl;
  }

  return 0;  
}      

int draw(int H, int W, char* str, int count) {
  int size = H * W;

  count++;
  if(count > H) {
    return 0;
  }
  
  for(int i = 0; i < W; i++){
    if(str[i] == '.') str[i] = '#';
    else str[i] = '.';
  }
  str[W] = '\0';
  cout << str << endl;
  draw(H, W, str, count);  
  return 0;
}  