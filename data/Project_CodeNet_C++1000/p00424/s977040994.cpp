#include <iostream>
#include <cstdio>
using namespace std;
char in[100000000];
int main(void) {
  int n;
  unsigned long long m;
  char bfr[200], aft[200];
  int flag = 0;

  while(1) {
    cin >> n;
    if(n == 0) break;
    for(int i = 0 ; i < n ; i++) {
      cin >> bfr[i] >> aft[i];
    }
    cin >> m;
    for(int i = 0 ; i < m ; i++) {
      cin >> in[i];
    }
    
    for(int i = 0 ; i < m ; i++) {
      for(int j = 0 ; j < n ; j++) {
	if(in[i] == bfr[j] && flag == 0) {
	  in[i] = aft[j];
	  flag = 1;
	}
      }
      flag = 0;
    }
    
    for(int i = 0 ; i < m ; i++) {
      cout << in[i];
    }
    cout << endl;
    for(int i = 0 ; i < 200 ; i++) {
      bfr[i] = 0;
      aft[i] = 0;
    }   
  }
  return 0;
}