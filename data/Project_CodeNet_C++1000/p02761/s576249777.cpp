#include <iostream>
#include <map>

int main(){
   int N, M;
   std::cin >> N >> M;
   std::map<int, int> mp;
   bool flag = true;
   for (int i=0; i<M; i++){
      int key, val;
      std::cin >> key >> val;
      if (mp.find(key) == mp.end()){
         mp[key] = val;
      } else{
         if (mp[key] != val){
            flag = false;
         }
      }
   }
   if (mp.find(1) != mp.end()){
      if ((N != 1) && mp[1] == 0){
         flag = false;
      }
   }
   if (!flag){
      std::cout << -1 << std::endl;
      return 0;
   }

   bool flag2 = false;
   for (int i=1; i<=N; i++){
      if (mp.find(i) != mp.end()){
         flag2 = true;
      }
      if (flag2){
         std::cout << mp[i];
      } else{
         if (N == 1){
            std::cout << 0;
         } else{
            std::cout << 1;
            flag2 = true;
         }
      }
   }
   std::cout << std::endl;


}

