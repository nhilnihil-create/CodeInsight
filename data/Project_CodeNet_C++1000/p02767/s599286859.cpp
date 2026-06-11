#include <iostream>
#include <vector>
int main(){
 int n;
 std::cin >> n; 
 std::vector<int> v(n);
 int sqsum, simsum;
 sqsum = 0;simsum = 0;
 for (size_t i=0; i < n; i++){
   std::cin >> v[i];
   sqsum += v[i] * v[i];
   simsum += v[i];
 }
 double m = simsum * 1.0 / n;
 int c, f;
 c = sqsum - 2 * simsum * ceil(m) + n * ceil(m) * ceil(m);
 f = sqsum - 2 * simsum * floor(m) + n * floor(m) * floor(m);
 std::cout << (c < f ? c : f) << std::endl;
}