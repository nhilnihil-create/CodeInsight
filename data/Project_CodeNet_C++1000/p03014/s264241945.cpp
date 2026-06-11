#include <bits/stdc++.h>
using namespace std;

int main() {
   int H,W;
   cin >> H >> W;
   string S[H];
   for (int i=0; i<H; i++) {
       cin >> S[i];
   }
   vector<vector<int>> X(H,vector<int> (W));
   for (int i=0; i<H; i++) {
       for (int j=0; j<W; j++) {
           if (j==0) {
               if (S[i][j]=='#') X[i][j]=0;
               else X[i][j]=1;
           }
           else {
               if (S[i][j]=='#') X[i][j]=0;
               else X[i][j]=X[i][j-1]+1;
           }
       }
       for (int j=W-2; j>=0; j--) {
           if (X[i][j]!=0) X[i][j]=max(X[i][j],X[i][j+1]);
       }
   }
   vector<vector<int>> Y(H,vector<int> (W));
   for (int j=0; j<W; j++) {
       for (int i=0; i<H; i++) {
           if (i==0) {
               if (S[i][j]=='#') Y[i][j]=0;
               else Y[i][j]=1;
           }
           else {
               if (S[i][j]=='#') Y[i][j]=0;
               else Y[i][j]=Y[i-1][j]+1;
           }
       }
       for (int i=H-2; i>=0; i--) {
           if (Y[i][j]!=0) Y[i][j]=max(Y[i][j],Y[i+1][j]);
       }
   }
   int count=0;
   for (int i=0; i<H; i++) {
       for (int j=0; j<W; j++) {
           int z=X[i][j]+Y[i][j];
           if (count<z) count=z;
       }
   }
   cout << count-1 << endl;
}