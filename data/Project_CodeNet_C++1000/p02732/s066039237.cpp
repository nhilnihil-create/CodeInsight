#include <iostream>
#include <vector>
#include <map>

int main(){
   int N;
   std::cin >> N;
   std::vector<int> A(N);
   for (int i=0; i<N; i++){
      std::cin >> A.at(i);
   }

   std::map<int, long long int> mp;
   for (int i=0; i<N; i++){
      mp[A.at(i)]++;
   }

   long long int sum = 0;
   for (auto x : mp){
      sum = sum + x.second * (x.second-1) /2;
   }

   for (int i=0; i<N; i++){
      int n = mp[A.at(i)];
      std::cout << sum-(n-1) << std::endl;
   }
}

