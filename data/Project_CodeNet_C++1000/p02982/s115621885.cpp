#include <bits/stdc++.h>
using namespace std;


int main() {
   
   int n, d;
   cin >> n >> d;
   
   vector<vector<int>> v(n, vector<int>(d));
   
   for (int i=0; i<n; i++) {
       for (int j=0; j<d; j++)
          cin >> v.at(i).at(j);
   }
   
   int ans =0;
   
   for (int i=0; i<n-1; i++) {
      for (int j=i+1; j<n; j++) {
        int distance = 0;
          for (int k=0; k<d; k++) {
              distance += pow(v.at(i).at(k) - v.at(j).at(k), 2);
          }
          if (ceil(sqrt(distance)) == floor(sqrt(distance))) ans++;
      }
   }
   cout << ans << endl;
}