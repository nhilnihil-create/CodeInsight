#include <iostream>
#include <string>
using namespace std;

char outc(int button, int cnt) {
  static char s[10] = {' ',' ','a','d','g','j','m','p','t','w'};
  static int a[10] = {0,0,3,3,3,3,3,4,3,4};
  if(button == 1) {
    switch(cnt%5) {
    case 1:return '.';
    case 2:return ',';
    case 3:return '!';
    case 4:return '?';
    case 0:return ' ';
    }
  } else {
    return s[button] +  (cnt-1)%a[button];
  }
}

main() {
  int N;
  int button;
  int cnt;
  cin >> N;
  getchar();
  for(int t = 0; t < N; t++) {
    button = 0;
    while(1) {
      char c = getchar();
      if(button == 0 && c != '0') {
	button = int(c-'0');
	cnt = 1;
      } else if(button != 0 && c == '0') {
	cout << outc(button, cnt);
	button = 0;
      } else {
	cnt++;
      }
      if(c == '\n') break;
    }
    cout << endl;
  }
}