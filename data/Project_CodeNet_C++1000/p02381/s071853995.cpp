#include <iostream>
#include <iomanip>
#include <cmath>

#define MAX_SIZE (1000)
#define MAX_SET  (1000)

using namespace std;

int main()
{
    int n;
    int size;
          
    double* alpha = new double[MAX_SIZE + 1];
    
    for (int i = 0; i < MAX_SIZE + 1; i++) {      
         do {
             cin >> n;
         } while (n > MAX_SET);
         
         if (n == 0) {
             size = i;
	     break;
         } else {      
             int* s = new int[n];       	    
             int  sum = 0;
             int  sum_sq = 0;

	     for (int j = 0; j < n; j++) {
	          do {
	              cin >> s[j];
		  } while (s[j] < 0 || s[j] > 100);
            
                  sum += s[j];
                  sum_sq += s[j] * s[j];                  
             }

             alpha[i] = sqrt((double)sum_sq / n - pow((double)sum / n, 2));
             
             delete[] s;       
          }                  
    }
  
    for (int i = 0; i < size; i++) {
         cout << fixed << setprecision(8) << alpha[i] << endl;         
    }

    delete[] alpha;
    
    return (0);
}