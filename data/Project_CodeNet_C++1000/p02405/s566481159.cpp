#include <iostream>

#define MAX_SET (1000)

using namespace std;

void draw_chessboard(int H, int W);

int main()
{  
    int  i;
    int* H = new int[MAX_SET + 1];
    int* W = new int[MAX_SET + 1];
    int  size;

    for (int i = 0; i < MAX_SET + 1; i++) {
         do {
             cin >> H[i] >> W[i];
         } while (H[i] > 300 || W[i] > 300);

         if (H[i] == 0 && W[i] == 0) {	    
             size = i;
	     break;
         }
    }
    
    for (int i = 0; i < size; i++) {
         draw_chessboard(H[i], W[i]);    
         cout << endl;         
    }

    delete[] H;
    delete[] W;
 
    return (0);
} 

void draw_chessboard(int H, int W)
{    
     for (int i = 1; i <= H; i++) {
          if (i % 2 == 1) {
              for (int j = 1; j <= W; j++) {
	   	   if (j % 2 == 1) {
		       cout << "#";
                   } else {
		       cout << ".";
                   }
              }
          } else {
	      for (int j = 1; j <= W; j++) {
		   if (j % 2 == 0) {
		       cout << "#";
                   } else {
		       cout << ".";
                   }
	      }
          }

          cout << endl;
     }
}