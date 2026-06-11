#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main() {
  int x;
  int rate;
  cin >> x;
  if (400 <= x) {
    if (600 <= x) {
      if (800 <= x) {
        if (1000 <= x) {
          if (1200 <= x) {
            if (1400 <= x) {
              if (1600 <= x) {
                if (1800 <= x) {
                  rate = 1;
                } else {
                  rate = 2;
                }
              } else {
                rate = 3;
              }
            } else {
              rate = 4;
            }
          } else {
            rate = 5;
          }
        } else {
          rate = 6;
        }
      } else {
        rate = 7;
      }
    } else {
      rate = 8;
    }
  }
  cout << rate << endl;
}