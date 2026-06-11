#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

using DVector = vector<double>;

double Average(DVector& vec) {
   double sumVal{0};
   for (auto element : vec) {
      sumVal += element;
   }
   return sumVal / vec.size();
}

double Variance(DVector& vec) {
   double sumVal{0}, average{Average(vec)};
   for (auto element : vec) {
      sumVal += pow(average - element, 2);
   }
   return sumVal / vec.size();
}

double StdDev(DVector& vec) {
   return sqrt(Variance(vec));
}

int main() {

   int n{};

   while (cin >> n, n > 0) {
      
      DVector s(n, 0);
      
      for (int i = 0; i < n; ++i) {
         cin >> s[i];
      }
      
      cout << fixed << StdDev(s) << endl;
   }

   return 0;

}