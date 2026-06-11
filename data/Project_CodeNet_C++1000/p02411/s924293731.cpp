#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;

int main(){
  int n, m, l;
  while (1) {
    cin >> n >> m >> l;
    if((n == -1) && (m == -1) && (l == -1)) {
      break;
    } else if ((n == -1) || (m == -1)) {
      cout << 'F' << endl;
    } else if (n + m >= 80) {
      cout << 'A' << endl;
    } else if (n + m >= 65) {
      cout << 'B' << endl;
    } else if (n + m >= 50) {
      cout << 'C' << endl;
    } else if (n + m >= 30) {
      if (l >= 50) {
        cout << 'C' << endl;
      } else {
        cout << 'D' << endl;
      }
    } else {
      cout << 'F' << endl;
    }
  }

}