#include <bits/stdc++.h>
using namespace std;

int main() {
   int X[3][3];

   for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
         cin >> X[i][j];
      }
   }

   int n;
   cin >> n;
   for(int b=0; b<n; b++) {
      int y;
      cin >> y;
      for(int i=0; i<3; i++) {
         for(int j=0; j<3; j++) {
            if(X[i][j] == y) X[i][j] = 0;
         }
      }
   }


   for(int i=0; i<3; i++) {
      int row_sum = 0;
      int column_sum = 0;
      for(int j=0; j<3; j++) {
         row_sum += X[i][j];
         column_sum += X[j][i];
      }
      if(row_sum == 0 || column_sum == 0) {
         cout << "Yes" << endl;
         return 0;
      }
   }
   if(X[0][0] + X[1][1] + X[2][2] == 0 || X[0][2] + X[1][1] + X[2][0] == 0) {
      cout << "Yes" << endl;
      return 0;
   }
   cout << "No" << endl;
}