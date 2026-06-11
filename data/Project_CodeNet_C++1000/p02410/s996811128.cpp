#include<iostream>

using namespace std;

int main() {
   int n,m,add,A[100][100],b[100];
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
           cin >> A[i][j];
       }
   }
   for (int j = 0; j < m; j++) {
       cin >> b[j];
   }
   for(int i = 0; i < n; i++) {
       add = 0;
       for (int j = 0; j < m; j++) {
           add += A[i][j] * b[j];
       }
       cout << add << endl;
   }
   return 0;
}