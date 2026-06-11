#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double Distance(vector<int>& vec1, vector<int>& vec2, int dimention) {
   double distance{0};
   const int number = vec1.size();
   for (int i = 0; i < number; ++i) {
      distance += pow(abs(vec1[i] - vec2[i]), dimention);
   }
   return pow(distance, 1.0 / dimention);
}

double ChebyshevDistance(vector<int>& vec1,vector<int>& vec2) {
   int distance{0};
   const int number = vec1.size();
   for (int i = 0; i < number; ++i) {
      distance= max(abs(vec1[i] - vec2[i]), distance);
   }
   return distance;
}

int main() {

   int n;
   cin >> n;

   vector<int> x(n, 0), y(n, 0);
   for (int i = 0; i < n; ++i) {
      cin >> x[i];
   }
   for (int i = 0; i < n; ++i) {
      cin >> y[i];
   }

   cout << fixed << Distance(x, y, 1) << endl;
   cout << fixed << Distance(x, y, 2) << endl;
   cout << fixed << Distance(x, y, 3) << endl;
   cout << fixed << ChebyshevDistance(x, y) << endl;

   return 0;

}