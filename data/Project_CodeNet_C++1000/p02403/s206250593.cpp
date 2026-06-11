#include <iostream>

#define MAX_SET (1000)

using namespace std;

void draw_rectangle(int H, int W);

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
         draw_rectangle(H[i], W[i]);         
         cout << endl;
    }

    delete[] H;
    delete[] W;
 
    return (0);
} 

void draw_rectangle(int H, int W)
{   
     for (int i = 1; i <= H; i++) {
          for (int j = 1; j <= W; j++) {
	       cout << "#";
          }

          cout << endl;
     }
}