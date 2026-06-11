#include <bits/stdc++.h>

int main(){
   int N, K;
   std::cin >> N >> K;
   std::vector<int> p(N);
   for (int i=0; i<N; i++){
      std::cin >> p.at(i);
   }
   std::vector<double> e(N);
   for (int i=0; i<N; i++){
      e.at(i) = (1+p.at(i)) * p.at(i) / p.at(i) / 2.0;
      //std::cerr << e.at(i) << std::endl;
   }
   double init_sum = 0.0;
   for (int i=0; i<K; i++){
      init_sum = init_sum + e.at(i);
   }
   //std::cerr << init_sum << std::endl;
   double tmp_sum = init_sum;
   double max_sum = init_sum;
   int j=0;
   for (int i=K; i<N; i++){
      tmp_sum = tmp_sum + e.at(i) - e.at(j);
      //std::cerr << tmp_sum << std::endl;
      max_sum = std::max(max_sum, tmp_sum);
      j++;
   }
   std::cout << std::setprecision(10) << max_sum << std::endl;

}

