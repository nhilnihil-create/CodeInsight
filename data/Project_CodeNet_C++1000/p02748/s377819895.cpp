#include <iostream>
#include <vector>
#include <algorithm>

int main(){
   int A, B, M;
   std::cin >> A >> B >> M;
   std::vector<int> a(A);
   std::vector<int> b(B);
   std::vector<std::pair<std::pair<int, int>, int>> t(M);
   for (int i=0; i<A; i++){
      std::cin >> a.at(i);
   }
   for (int j=0; j<B; j++){
      std::cin >> b.at(j);
   }
   for (int k=0; k<M; k++){
      int x, y, c;
      std::cin >> x >> y >> c;
      std::pair<int, int> p = {x, y};
      std::pair<std::pair<int, int>, int> pp = {p, c};
      t.at(k) = pp;
   }
   auto min_iter_a = std::min_element(a.begin(), a.end());
   auto min_index_a = std::distance(a.begin(), min_iter_a);
   auto min_iter_b = std::min_element(b.begin(), b.end());
   auto min_index_b = std::distance(b.begin(), min_iter_b);
   int min = a.at(min_index_a) + b.at(min_index_b);
   std::cerr << min << std::endl;

   for (auto x : t){
      int tmp = a.at(x.first.first-1) + b.at(x.first.second-1) - x.second;
      min = std::min(tmp, min);
   }
   std::cout << min << std::endl;
}
