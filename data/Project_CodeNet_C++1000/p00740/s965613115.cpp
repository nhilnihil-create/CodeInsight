#include <iostream>
using namespace std;

int main(void) {
      int n, p;
      int bowl, turn, stones;


      while(1) {
          cin >> n >> p;
          if( (n+p) == 0 ) break;


          int* candidate = new int[n];
          for(int i=0; i < n; i++) {
            candidate[i] = 0;
          }
          turn = 0;
          stones = p;
          while(1) {

              if(stones > 0) { //?¢????????°???????????????????
                  stones--;
                  if(++candidate[turn%n] == p) break;
                  turn++;
              } else if(stones == 0) {  //?¢?????°?????????\??????
                  stones += candidate[turn%n];
                  candidate[turn%n] = 0;
                  turn++;
              }
          }
          cout << turn%n << endl;

      }




}